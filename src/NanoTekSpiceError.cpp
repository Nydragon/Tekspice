/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include <vector>
#include <iostream>
#include <fstream>
#include "NanoTekSpiceError.hpp"

nts::NanoTekSpiceError::NanoTekSpiceError(const std::string &message)
{
    this->_message = message;
}

const char *nts::NanoTekSpiceError::what() const noexcept
{
    return this->_message.c_str();
}

std::string const &nts::NanoTekSpiceError::getComponent() const
{
    return this->_component;
}

nts::FileNotFound::FileNotFound(const std::string &path)
    : NanoTekSpiceError("File: " + path + " not found.")
{
}

nts::InvalidLink::InvalidLink(const std::string &type, const std::string &line)
    : NanoTekSpiceError("Right hand side of link for component \"" + type + "\" has to refer to self, here: \"" + line + "\"")
{
}

nts::SyntaxError::SyntaxError(const std::string &line, int line_no)
    : NanoTekSpiceError("Line " + std::to_string(line_no) + ": \"" + line + "\" contains a syntax error.")
{
}

nts::NameUsedError::NameUsedError(const std::string &name)
    : NanoTekSpiceError("Component name \"" + name + "\" already in use.")
{
}

void nts::validateArgs(int count, char *args_c[])
{
    std::vector<std::string> args;

    for (int i = 1; i < count; i++)
        args.emplace_back(args_c[i]);
    if (args.empty())
        exit(84);
    for (const auto &arg: args) {
        if (arg == "-h") {
            std::cout << "Enter a filename in param : ./nanotekspice [filename]" << std::endl;
            exit(0);
        } else {
            std::ifstream input_file(arg);
            if (!input_file.is_open())
                throw nts::FileNotFound(arg);
        }
    }
}

nts::PinNotFoundError::PinNotFoundError(const std::string &name, size_t pin)
    : NanoTekSpiceError("Pin \"" + std::to_string(pin) + "\" not found in " + name + ".")
{
}
