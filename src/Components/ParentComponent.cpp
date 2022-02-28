/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include <iomanip>
#include "ParentComponent.hpp"
#include "../NanoTekSpiceError.hpp"

std::string nts::ParentComponent::getName() const
{
    return this->_name;
}

std::string nts::ParentComponent::getType() const
{
    return this->_type;
}

nts::ParentComponent::ParentComponent(const std::string &name, const std::string &type)
{
    this->_name = name;
    this->_type = type;
}

void nts::ParentComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    int index = this->findPinIndex(pin);

    if (this->pins[index].outer_connection.comp_r == &other && this->pins[index].outer_connection.pin == otherPin)
        return;
    this->pins[index].outer_connection.comp_r = &other;
    this->pins[index].outer_connection.pin = otherPin;

    other.setLink(otherPin, static_cast<IComponent &>(*this), pin);
}

int nts::ParentComponent::findPinIndex(size_t pin) const
{
    int i = 0;

    for (auto &pin_s: this->pins) {
        if (pin_s.number == pin)
            return i;
        i++;
    }

    throw nts::PinNotFoundError(this->getName(), pin);
}

void nts::ParentComponent::dump() const
{
    int col_w = 15;

    std::cout << "Component " << this->getType() << " \"" << this->getName() << "\"" << std::endl;
    std::cout << std::setw(col_w) << "Pin No."
              << std::setw(col_w) << "outer con"
              << std::setw(col_w) << "outer con Pin"
              << std::setw(col_w) << "inner con"
              << std::setw(col_w) << "inner con Pin"
              << std::setw(col_w) << "state" << std::endl;
    for (auto &pin: this->pins) {
        std::cout << std::setw(col_w) << pin.number
                  << std::setw(col_w) << (pin.outer_connection.comp_r != nullptr ? "YES" : "N/A")
                  << std::setw(col_w) << (pin.outer_connection.comp_r != nullptr ? std::to_string(pin.outer_connection.pin) : "N/A")
                  << std::setw(col_w) << (pin.inner_connection.gate_r != nullptr ? "YES" : "N/A")
                  << std::setw(col_w) << (pin.inner_connection.gate_r != nullptr ? std::to_string(pin.inner_connection.pin) : "N/A")
                  << std::setw(col_w) << TRI(pin.state)
                  << std::endl;
    }
}
