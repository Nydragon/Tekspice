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
    if (this->getPin(1) == nts::Tristate::TRUE && this->getPin(2) == nts::Tristate::TRUE)
        this->setPin(3, nts::Tristate::FALSE);
    else
        this->setPin(3, nts::Tristate::TRUE);
    return this->getPin(3);
}
