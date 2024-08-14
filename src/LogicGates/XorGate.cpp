/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "XorGate.hpp"

nts::XorGate::XorGate(std::string name) : GenericGate(name) {}

nts::Tristate nts::XorGate::compute() {
  if (IS_UNDEFINED(this->getPin(1)) || IS_UNDEFINED(this->getPin(2)))
    this->setPin(3, nts::Tristate::UNDEFINED);
  else if (this->getPin(1) == nts::Tristate::TRUE &&
           this->getPin(2) == nts::Tristate::TRUE)
    this->setPin(3, nts::Tristate::FALSE);
  else if (this->getPin(1) == FALSE && this->getPin(2) == FALSE)
    this->setPin(3, nts::Tristate::FALSE);
  else
    this->setPin(3, nts::Tristate::TRUE);
  return this->getPin(3);
}
