/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "NandGate.hpp"

nts::NandGate::NandGate(std::string name) : GenericGate(name) {}

nts::Tristate nts::NandGate::compute()
{
    if (IS_UNDEFINED(this->getPin(1)) || IS_UNDEFINED(this->getPin(2)))
        this->setPin(3, nts::Tristate::UNDEFINED);
    else if (IS_TRUE(this->getPin(1)) && IS_TRUE(this->getPin(2)))
        this->setPin(3, nts::Tristate::FALSE);
    else
        this->setPin(3, nts::Tristate::TRUE);
    return this->getPin(3);
}
