/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include <iostream>
#include <iomanip>
#include "GenericGate.hpp"
#include "../Components/ParentComponent.hpp"

nts::GenericGate::GenericGate(const std::string &name)
{
    this->_name = name;

    this->pins.resize(3);
    this->pins[0] = {.number = 1};
    this->pins[1] = {.number = 2};
    this->pins[2] = {.number = 3};
}

std::string nts::GenericGate::getName()
{
    return this->_name;
}

void nts::GenericGate::setLink(std::size_t pin, nts::ILogicGate &other, std::size_t otherPin)
{
    int index = this->findPinIndex(pin);

    auto state = std::make_shared<nts::Tristate>(nts::Tristate::UNDEFINED);

    this->pins[index].inner_connection.gate_r = &other;
    this->pins[index].inner_connection.pin = otherPin;
    this->pins[index].state = state;

    auto *downcastedGate = dynamic_cast<GenericGate *>(&other);

    int otherIndex = downcastedGate->findPinIndex(otherPin);

    downcastedGate->pins[otherIndex].inner_connection.gate_r = this;
    downcastedGate->pins[otherIndex].inner_connection.pin = pin;
    downcastedGate->pins[otherIndex].state = state;
}

void nts::GenericGate::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    auto *downcastedComponent = dynamic_cast<ParentComponent *>(&other);

    int otherIndex = downcastedComponent->findPinIndex(otherPin);
    int index = this->findPinIndex(pin);

    auto state = std::make_shared<nts::Tristate>(nts::Tristate::UNDEFINED);;

    this->pins[index].outer_connection.comp_r = &other;
    this->pins[index].outer_connection.pin = otherPin;
    this->pins[index].state = state;

    downcastedComponent->pins[otherIndex].inner_connection.gate_r = this;
    downcastedComponent->pins[otherIndex].inner_connection.pin = pin;
    downcastedComponent->pins[otherIndex].state = state;
}

int nts::GenericGate::findPinIndex(size_t pin) const
{
    int i = 0;

    for (auto &pin_s: this->pins) {
        if (pin_s.number == pin)
            return i;
        i++;
    }
    return -1;
}

void nts::GenericGate::dump()
{
    int col_w = 15;

    std::cout << "Gate \"" << this->getName() << "\"" << std::endl;
    std::cout << std::setw(col_w) << "Pin No."
              << std::setw(col_w) << "outer con"
              << std::setw(col_w) << "outer con Pin"
              << std::setw(col_w) << "inner con"
              << std::setw(col_w) << "inner con Pin"
              << std::setw(col_w) << "state" << std::endl;
    for (auto &pin: this->pins) {
        std::cout << std::setw(col_w) << pin.number
                  << std::setw(col_w) << (pin.outer_connection.comp_r != nullptr ? dynamic_cast<ParentComponent *>(pin
            .outer_connection.comp_r)->getName() : "N/A")
                  << std::setw(col_w) << (pin.outer_connection.comp_r != nullptr ? std::to_string(pin.outer_connection.pin) : "N/A")
                  << std::setw(col_w) << (pin.inner_connection.gate_r != nullptr ? pin.inner_connection.gate_r->getName() : "N/A")
                  << std::setw(col_w) << (pin.inner_connection.gate_r != nullptr ? std::to_string(pin.inner_connection.pin) : "N/A")
                  << std::setw(col_w) << TRI(pin.state)
                  << std::endl;
    }
}

void nts::GenericGate::setPin(size_t pin, nts::Tristate state)
{
    *(this->pins[this->findPinIndex(pin)].state) = state;
}

nts::Tristate nts::GenericGate::getPin(size_t pin) const
{
    return *this->pins[this->findPinIndex(pin)].state;
}

std::vector<nts::pin_t *> nts::GenericGate::outputPins()
{
    std::vector<pin_t *> res(1);
    res[0] = &this->pins[this->findPinIndex(3)];
    return res;
}
