/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "NotGate.hpp"

nts::NotGate::NotGate(const std::string &name) : GenericGate(name) {}

nts::Tristate nts::NotGate::compute() {
  if (IS_UNDEFINED(this->getPin(1)))
    this->setPin(2, nts::Tristate::UNDEFINED);
  else if (this->getPin(1) == nts::Tristate::TRUE)
    this->setPin(2, nts::Tristate::FALSE);
  else
    this->setPin(2, nts::Tristate::TRUE);
  return this->getPin(2);
}

std::vector<nts::pin_t *> nts::NotGate::outputPins() {
  std::vector<pin_t *> res(1);
  res[0] = &this->pins[this->findPinIndex(2)];
  return res;
}
