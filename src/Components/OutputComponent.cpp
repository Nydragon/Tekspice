/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "OutputComponent.hpp"

nts::OutputComponent::OutputComponent(const std::string &name)
    : ParentComponent(name, "output")
{
    this->_pin_no = 1;
    this->pins.resize(1);
    this->pins[0] = {.number =  1, .state = std::make_unique<nts::Tristate>(nts::Tristate::UNDEFINED)};
    this->_tick = 0;
    this->_state = new nts::Tristate(nts::Tristate::UNDEFINED);
}

void nts::OutputComponent::simulate(std::size_t tick)
{
    this->_tick++;

    this->compute(1);
}

nts::Tristate nts::OutputComponent::compute(std::size_t pin)
{
    int index = this->findPinIndex(pin);

    *this->_state = *this->pins[index].state;
    return *this->_state;
}

void nts::OutputComponent::setState(nts::Tristate state)
{
    *this->_state = state;
}

nts::Tristate nts::OutputComponent::getState() const
{
    int index = this->findPinIndex(1);

    return *this->pins[index].state;
}

nts::OutputComponent::~OutputComponent()
{
    delete this->_state;
}
