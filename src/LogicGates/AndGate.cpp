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
    if (IS_FALSE(this->getPin(1)) || IS_FALSE(this->getPin(2)))
        this->setPin(3, nts::Tristate::FALSE);
    else if (IS_UNDEFINED(this->getPin(1)) || IS_UNDEFINED(this->getPin(2)))
        this->setPin(3, nts::Tristate::UNDEFINED);
    else
        this->setPin(3, nts::Tristate::TRUE);
    return this->getPin(3);
}
