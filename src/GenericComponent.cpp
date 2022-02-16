/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include <fstream>
#include <iostream>
#include <regex>
#include <iomanip>
#include "GenericComponent.hpp"
#include "NanoTekSpiceError.hpp"
#include "LogicGates/AndGate.hpp"

#define KOWALSKI std::cout << "Kowalski, analysis." << std::endl;
#define C_ALL(a) cbegin(a), cend(a)

nts::GenericComponent::GenericComponent(const std::string &type, const std::string &name)
{

    std::ifstream input_file(nts::componentCfgLocation + type + ".cfg");
    this->_name = name;
    this->_type = type;

    if (!input_file.is_open())
        throw nts::FileNotFound(nts::componentCfgLocation + type + ".cfg");

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
                    this->pins[i] = {.number =  i + 1};
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

            if (compNameRight != "self")
                throw nts::InvalidLink(this->getType(), line);
            int pin_i = findPinIndex(pinNumRight);
            this->pins[pin_i].number = this->pins[pin_i].number ? this->pins[pin_i].number : pinNumRight;
            this->pins[pin_i].inner_connection.pin = pinNumLeft;
            this->pins[pin_i].inner_connection.gate_r = this->circuitry[gateIndex];
        }
    }
}

void nts::GenericComponent::simulate(std::size_t tick)
{
}

nts::Tristate nts::GenericComponent::compute(std::size_t pin)
{
    return nts::FALSE;
}

void nts::GenericComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    size_t index = this->findPinIndex(pin);

    if (this->pins[index].outer_connection.comp_r == &other && this->pins[index].outer_connection.pin == otherPin)
        return;
    this->pins[index].outer_connection.comp_r = &other;
    this->pins[index].outer_connection.pin = otherPin;
    other.setLink(otherPin, static_cast<IComponent &>(*this), pin);
}

void nts::GenericComponent::dump() const
{
    int col_w = 15;

    std::cout << "Component " << this->getType() << " \"" << this->getName() << "\"" << std::endl;
    std::cout << std::setw(col_w) << "Pin No."
              << std::setw(col_w) << "outer con"
              << std::setw(col_w) << "outer con Pin"
              << std::setw(col_w) << "inner con"
              << std::setw(col_w) << "inner con Pin"
              << std::setw(col_w) << "state" << std::endl;
    for (auto &pin: this->pins) {
        std::cout << std::setw(col_w) << pin.number
                  << std::setw(col_w) << (pin.outer_connection.comp_r != nullptr ? reinterpret_cast<GenericComponent *>(pin
            .outer_connection.comp_r)->getName() : "N/A")
                  << std::setw(col_w) << (pin.outer_connection.comp_r != nullptr ? std::to_string(pin.outer_connection.pin) : "N/A")
                  /**
                   * replace with GenericGate
                   */
                  << std::setw(col_w) << (pin.inner_connection.gate_r != nullptr ? reinterpret_cast<GenericGate *>(pin
            .inner_connection.gate_r)->getName() : "N/A")
                  << std::setw(col_w) << (pin.inner_connection.gate_r != nullptr ? std::to_string(pin.inner_connection.pin) : "N/A")
                  << std::setw(col_w) << pin.state
                  << std::endl;
    }
}

nts::ILogicGate *nts::GenericComponent::fetchGate(const std::string &type, const std::string &name)
{
    if ("and" == type)
        return new AndGate(name);
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

std::string nts::GenericComponent::getName() const
{
    return this->_name;
}

std::string nts::GenericComponent::getType() const
{
    return this->_type;
}

int nts::GenericComponent::findPinIndex(size_t pin) const
{

    int i = 0;

    for (auto &pin_s: this->pins) {
        if (pin_s.number == pin)
            return i;
        i++;
    }
    return -1;
}
