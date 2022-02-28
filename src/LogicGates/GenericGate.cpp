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

nts::Tristate nts::GenericGate::getInput1()
{
    return *this->pins[0].state;
}

nts::Tristate nts::GenericGate::getInput2()
{
    return *this->pins[1].state;
}

nts::Tristate nts::GenericGate::getOutput()
{
    return *this->pins[2].state;
}

std::string nts::GenericGate::getName()
{
    return this->_name;
}

void nts::GenericGate::setInput1(nts::Tristate value)
{
    *this->pins[0].state = value;
}

void nts::GenericGate::setInput2(nts::Tristate value)
{
    *this->pins[1].state = value;
}

void nts::GenericGate::setOutput(nts::Tristate value)
{
    *this->pins[2].state = value;
}

void nts::GenericGate::setLink(std::size_t pin, nts::ILogicGate &other, std::size_t otherPin)
{
    int i = this->findPinIndex(pin);

    if (this->pins[i].inner_connection.gate_r == &other && this->pins[i].inner_connection.pin == otherPin)
        return;
    this->pins[i].inner_connection.gate_r = &other;
    this->pins[i].inner_connection.pin = otherPin;

    other.setLink(otherPin, *this, pin);
}

void nts::GenericGate::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    int i = this->findPinIndex(pin);

    this->pins[i].outer_connection.comp_r = &other;
    this->pins[i].outer_connection.pin = otherPin;
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
                  << std::setw(col_w) << (pin.outer_connection.comp_r != nullptr ? reinterpret_cast<ParentComponent *>(pin
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

    for (auto &pin_s: this->pins) {
        if (pin_s.number == pin) {
            *pin_s.state = state;
        }
    }
}

nts::pin_t &nts::GenericGate::outputPin()
{
    return this->pins[2];
}

std::vector<nts::pin_t> nts::GenericGate::getPins()
{
    return this->pins;
}
