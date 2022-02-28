/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "InputComponent.hpp"

nts::InputComponent::InputComponent(const std::string &name, nts::Tristate state)
    : ParentComponent(name, "input")
{
    this->_pin_no = 1;
    this->pins.resize(1);
    this->pins[0] = {.number =  1, .state = state};
    this->_tick = 0;
}

void nts::InputComponent::simulate(std::size_t tick)
{
    this->_tick++;

    this->compute(1);
}

nts::Tristate nts::InputComponent::compute(std::size_t pin)
{
    int index = this->findPinIndex(pin);

    this->pins[index].state = this->_state;
    return this->_state;
}

void nts::InputComponent::setState(nts::Tristate state)
{
    this->_state = state;
}

nts::Tristate nts::InputComponent::getState() const
{
    return this->_state;
}
