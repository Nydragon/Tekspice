/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include <fstream>
#include <regex>
#include "GenericComponent.hpp"
#include "../NanoTekSpiceError.hpp"
#include "../LogicGates/Gates.hpp"

nts::GenericComponent::GenericComponent(const std::string &type, const std::string &name)
    : ParentComponent(name, type)
{

    std::ifstream input_file(this->componentCfgLocation + type + ".cfg");

    if (!input_file.is_open())
        throw nts::FileNotFound(this->componentCfgLocation + type + ".cfg");

    std::string line;
    const auto r = std::regex(R"(.*?(?=(#|$)))");
    int section = 99;

    while (std::getline(input_file, line)) {
        line = std::regex_token_iterator(C_ALL(line), r, 0)->str();
        if (line[0] == '.') {
            if (line == ".pins") {
                std::getline(input_file, line);
                this->_pin_no = std::stoi(line);
                this->pins.resize(this->_pin_no);
                for (size_t i = 0; i < this->_pin_no; i++)
                    this->pins[i] = {.number =  i + 1, .state =std::make_unique<nts::Tristate>(nts::Tristate::UNDEFINED)};
            } else if (line == ".circuitry") {
                section = 1;
            } else if (line == ".links")
                section = 2;
            continue;
        }

        char *token = std::strtok(const_cast<char *>(std::string(line).c_str()), " ");

        std::string left, right;

        if (token)
            left = std::string(token);
        if ((token = std::strtok(nullptr, " ")))
            right = std::string(token);

        if (section == 1) {
            this->circuitry.push_back(GenericComponent::fetchGate(left, right));
        }

        if (section == 2 && left != "null") {
            const auto beforeCol = std::regex(".+(?=:)");
            const auto afterCol = std::regex(":.+");
            std::string compNameLeft = std::regex_token_iterator(C_ALL(left), beforeCol, 0)->str();
            std::string compNameRight = std::regex_token_iterator(C_ALL(right), beforeCol, 0)->str();
            /**
             * I need to exclude the colon from the match but
             * \K and lookbehind do not work in c++ regex flavour
             * therefore I skip the first character of the match
             */
            size_t pinNumLeft = std::stoi(&std::regex_token_iterator(C_ALL(left), afterCol, 0)->str()[1]);
            size_t pinNumRight = std::stoi(&std::regex_token_iterator(C_ALL(right), afterCol, 0)->str()[1]);
            int gateIndex = findGateIndex(compNameLeft);
            int pin_i = this->findPinIndex(pinNumRight);

            if (compNameRight != "self") {
                int otherGateIndex = findGateIndex(compNameRight);

                this->circuitry[gateIndex]->setLink(pinNumLeft, *this->circuitry[otherGateIndex], pinNumRight);
            } else {

                this->pins[pin_i].number = this->pins[pin_i].number ? this->pins[pin_i].number : pinNumRight;
                this->pins[pin_i].inner_connection.pin = pinNumLeft;
                this->pins[pin_i].inner_connection.gate_r = this->circuitry[gateIndex];
                this->circuitry[gateIndex]->setLink(pinNumLeft, *this, pinNumRight);
            }
        }
    }
}

void nts::GenericComponent::simulate(std::size_t tick)
{
    for (auto &pin: this->pins) {
        if (pin.inner_connection.gate_r != nullptr)
            pin.inner_connection.gate_r->setPin(pin.inner_connection.pin, *pin.state);
    }
    int calculated = 0;

    while (calculated < 1) {
        for (auto &gate: this->circuitry) {
            std::vector<nts::pin_t> gatePins = gate->getPins();

            nts::Tristate newState = gate->compute();

            if (gate->outputPin().outer_connection.pin > 0) {
                *(this->pins[this->findPinIndex(gate->outputPin().outer_connection.pin)].state) = newState;
            } else if (gate->outputPin().inner_connection.pin > 0) {
                gate->outputPin().inner_connection.gate_r->setPin(gate->outputPin().inner_connection.pin, newState);
            }
        }
        calculated++;
    }
}

nts::Tristate nts::GenericComponent::compute(std::size_t pin)
{
    return this->pins[this->findPinIndex(pin)].inner_connection.gate_r->compute();
}

nts::ILogicGate *nts::GenericComponent::fetchGate(const std::string &type, const std::string &name)
{
    if ("and" == type)
        return new AndGate(name);
    else if ("nand" == type)
        return new NandGate(name);
    else if ("or" == type)
        return new OrGate(name);
    else if ("xor" == type)
        return new XorGate(name);
    else if ("nor" == type)
        return new NorGate(name);
    else if ("xnor" == type)
        return new XnorGate(name);
    else if ("not" == type)
        return new NotGate(name);
    else
        throw nts::NanoTekSpiceError("Gate: \"" + name + "\" not found");
}

int nts::GenericComponent::findGateIndex(const std::string &name) const
{
    int i = 0;

    for (auto &gate: this->circuitry) {
        if (gate && gate->getName() == name)
            return i;
        i++;
    }
    return -1;
}

nts::GenericComponent::~GenericComponent()
{
    for (auto &g: this->circuitry)
        delete g;
}
