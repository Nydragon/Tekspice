/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "FalseComponent.hpp"

nts::FalseComponent::FalseComponent(const std::string &name)
    : ParentComponent(name, "false") {
  this->_pin_no = 1;
  this->pins.resize(1);
  this->pins[0] = {.number = 1,
                   .state =
                       std::make_unique<nts::Tristate>(nts::Tristate::FALSE)};
  this->_tick = 0;
  this->_state = new nts::Tristate(nts::Tristate::FALSE);
}

nts::Tristate nts::FalseComponent::compute(std::size_t pin) {
  int index = this->findPinIndex(pin);

  *(this->pins[index].state) = *this->_state;

  return *this->_state;
}

void nts::FalseComponent::simulate(std::size_t tick) {
  this->_tick++;

  this->compute(1);
}

nts::FalseComponent::~FalseComponent() { delete this->_state; }

void nts::FalseComponent::setState([[maybe_unused]] nts::Tristate state) {}

nts::Tristate *nts::FalseComponent::getState() const { return this->_state; }
