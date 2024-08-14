/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "ClockComponent.hpp"

nts::ClockComponent::ClockComponent(const std::string &name)
    : ParentComponent(name, "clock") {
  this->_pin_no = 1;
  this->pins.resize(1);
  this->pins[0] = {
      .number = 1,
      .state = std::make_unique<nts::Tristate>(nts::Tristate::UNDEFINED)};
  this->_tick = 0;
  this->_state = new nts::Tristate(nts::Tristate::UNDEFINED);
}

nts::Tristate nts::ClockComponent::compute(std::size_t pin) {
  int index = this->findPinIndex(pin);

  *(this->pins[index].state) = *this->_state;

  return *this->_state;
}

void nts::ClockComponent::simulate(std::size_t tick) {
  this->_tick++;

  this->compute(1);

  this->setState(*this->_state == nts::Tristate::TRUE ? nts::Tristate::FALSE
                 : *this->_state == nts::Tristate::FALSE
                     ? nts::Tristate::TRUE
                     : nts::Tristate::UNDEFINED);
}

nts::ClockComponent::~ClockComponent() { delete this->_state; }

void nts::ClockComponent::setState(nts::Tristate state) {
  *this->_state = state;
}

nts::Tristate *nts::ClockComponent::getState() const { return this->_state; }
