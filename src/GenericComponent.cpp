/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include <fstream>
#include <iostream>
#include <regex>
#include "GenericComponent.hpp"
#include "NanoTekSpiceError.hpp"
#include "LogicGates/AndGate.hpp"

#define C_ALL(a) cbegin(a), cend(a)

nts::GenericComponent::GenericComponent(const std::string &type, const std::string &name)
{

    std::ifstream input_file(nts::componentCfgLocation + type + ".cfg");
    this->_name = name;

    if (!input_file.is_open())
        throw nts::FileNotFound(nts::componentCfgLocation + type + ".cfg");

    std::string line;
    const auto r = std::regex(R"(.*?(?=(#|$)))");
    int section = 99;

    while (std::getline(input_file, line)) {
        line = std::regex_token_iterator(C_ALL(line), r, 0)->str();

        if (line[0] == '.') {
            if (line == ".circuitry")
                section = 1;
            if (line == ".links")
                section = 2;
            continue;
        }

        char *token = std::strtok(const_cast<char *>(line.c_str()), " ");
        std::string left, right;

        if (token)
            left = std::string(token);
        if ((token = std::strtok(nullptr, " ")))
            right = std::string(token);

        if (section == 1) {
            this->circuitry.push_back(GenericComponent::fetchGate(left, right));
        }

        if (section == 2 && left != "null") {
            const auto nameReg = std::regex(R"(.*?(?=:))");
            std::string compName = std::regex_token_iterator(C_ALL(left), nameReg, 0)->str();
            int gateIndex = findGateIndex(compName);

            if (this->pins.size() <= gateIndex)
                this->pins.resize(gateIndex + 1, std::deque<size_t>(0));
            if (this->pins.at(gateIndex)[0] < left[-1] - 48)
                this->pins.at(gateIndex).push_front(std::stoi(right));
            else
                this->pins.at(gateIndex).push_back(std::stoi(right));
            sort(this->pins[gateIndex].begin() + 1, this->pins[gateIndex].end());
        }
    }

    for (auto &pin: this->pins) {
        for (auto &n: pin) {
            std::cout << n << " ";
        }
        std::cout << std::endl;
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
}

void nts::GenericComponent::dump() const
{
}

nts::ILogicGate *nts::GenericComponent::fetchGate(const std::string &type, const std::string &name)
{
    if ("and" == type)
        return new AndGate(name);
    else
        throw nts::NanoTekSpiceError("Gate: \"" + name + "\" not found");
}

int nts::GenericComponent::findGateIndex(const std::string &name)
{
    int i = 0;

    for (auto &gate: this->circuitry) {
        if (gate && gate->getName() == name)
            return i;
        i++;
    }
    return -1;
}
