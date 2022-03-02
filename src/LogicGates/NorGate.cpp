/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "NorGate.hpp"

nts::NorGate::NorGate(std::string name) : GenericGate(name) {}

nts::Tristate nts::NorGate::compute()
{
    if (this->getPin(1) == nts::Tristate::FALSE && this->getPin(2) == nts::Tristate::FALSE)
        this->setPin(3, nts::Tristate::TRUE);
    else
        this->setPin(3, nts::Tristate::FALSE);
    return this->getPin(3);
}
