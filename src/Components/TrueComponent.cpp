/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "TrueComponent.hpp"

nts::TrueComponent::TrueComponent(const std::string &name)
    : ParentComponent(name, "true") {
  this->_pin_no = 1;
  this->pins.resize(1);
  this->pins[0] = {.number = 1,
                   .state =
                       std::make_unique<nts::Tristate>(nts::Tristate::TRUE)};
  this->_tick = 0;
  this->_state = new nts::Tristate(nts::Tristate::TRUE);
}

nts::Tristate nts::TrueComponent::compute(std::size_t pin) {
  int index = this->findPinIndex(pin);

  *(this->pins[index].state) = *this->_state;

  return *this->_state;
}

nts::TrueComponent::~TrueComponent() { delete this->_state; }

void nts::TrueComponent::simulate(std::size_t tick) {
  this->_tick++;

  this->compute(1);
}

void nts::TrueComponent::setState([[maybe_unused]] nts::Tristate state) {}

nts::Tristate *nts::TrueComponent::getState() const { return this->_state; }
