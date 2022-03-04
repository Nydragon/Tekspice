/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "OrGate.hpp"

nts::OrGate::OrGate(std::string name) : GenericGate(name)
{
}

nts::Tristate nts::OrGate::compute()
{
    if (IS_UNDEFINED(this->getPin(1)) || IS_UNDEFINED(this->getPin(2)))
        this->setPin(3, nts::Tristate::UNDEFINED);
    else if (this->getPin(1) == nts::Tristate::TRUE || this->getPin(2) == nts::Tristate::TRUE) {
        this->setPin(3, nts::Tristate::TRUE);
    } else
        this->setPin(3, nts::Tristate::FALSE);
    return this->getPin(3);
}
