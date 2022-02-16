/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

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

nts::FileNotFound::FileNotFound(const std::string &path) : NanoTekSpiceError("File: " + path + " not found.")
{
}

nts::InvalidLink::InvalidLink(const std::string &type, const std::string &line)
    : NanoTekSpiceError("Right hand side of link for component \"" + type + "\" has to refer to self, here: \"" + line + "\"")
{
}
