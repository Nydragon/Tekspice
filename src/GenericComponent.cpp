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

#define C_ALL(a) cbegin(a), cend(a)

nts::GenericComponent::GenericComponent(const std::string &type, const std::string &name)
{

    std::ifstream input_file(nts::componentCfgLocation + type + ".cfg");

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
        std::string left;
        std::string right;
        if (token)
            left = std::string(token);
        if ((token = std::strtok(nullptr, " ")))
            right = std::string(token);

        if (!left.empty() && !right.empty()) {
            std::cout << left << " --- " << right << std::endl;
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
}

void nts::GenericComponent::dump() const
{
}

nts::ILogicGate nts::GenericComponent::fetchGate(const std::string &name)
{
}
