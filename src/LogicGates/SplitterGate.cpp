/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "SplitterGate.hpp"

nts::Tristate nts::SplitterGate::compute()
{
    auto state = this->getPin(1);

    this->setPin(2, state);
    this->setPin(3, state);
    return state;
}

nts::SplitterGate::SplitterGate(const std::string &_name) : GenericGate(_name)
{
}

std::vector<nts::pin_t *> nts::SplitterGate::outputPins()
{
    std::vector<pin_t *> res(2);
    res[0] = &this->pins[this->findPinIndex(2)];
    res[1] = &this->pins[this->findPinIndex(3)];
    return res;
}
