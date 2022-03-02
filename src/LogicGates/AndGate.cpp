/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include <iostream>
#include "AndGate.hpp"

nts::AndGate::AndGate(const std::string &name) : GenericGate(name)
{
}

nts::Tristate nts::AndGate::compute()
{
    if (this->getPin(1) == nts::Tristate::TRUE && this->getPin(2) == nts::Tristate::TRUE)
        this->setPin(3, nts::Tristate::TRUE);
    else
        this->setPin(3, nts::Tristate::FALSE);
    return this->getPin(3);
}
