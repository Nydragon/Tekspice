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

    auto state = std::make_shared<nts::Tristate>(nts::Tristate::UNDEFINED);

    this->pins[index].outer_connection.comp_r = &other;
    this->pins[index].outer_connection.pin = otherPin;
    this->pins[index].state = state;

    auto *downcastedComponent = dynamic_cast<ParentComponent *>(&other);

    int otherIndex = downcastedComponent->findPinIndex(otherPin);

    downcastedComponent->pins[otherIndex].outer_connection.comp_r = this;
    downcastedComponent->pins[otherIndex].outer_connection.pin = pin;
    downcastedComponent->pins[otherIndex].state = state;
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
    int w = 15;

    std::cout << "Component " << this->getType() << " \"" << this->getName() << "\"" << std::endl;
    std::cout << std::setw(w) << "Pin No."
              << std::setw(w) << "outer con"
              << std::setw(w) << "outer con Pin"
              << std::setw(w) << "inner con"
              << std::setw(w) << "inner con Pin"
              << std::setw(w) << "state" << std::endl;

    for (auto &pin: this->pins) {
        std::cout << std::setw(w) << pin.number
                  << std::setw(w)
                  << (pin.outer_connection.comp_r != nullptr ? dynamic_cast<ParentComponent *>(pin.outer_connection.comp_r)->getName()
                                                             : "N/A")
                  << std::setw(w) << (pin.outer_connection.comp_r != nullptr ? std::to_string(pin.outer_connection.pin) : "N/A")
                  << std::setw(w) << (pin.inner_connection.gate_r != nullptr ? "YES" : "N/A")
                  << std::setw(w) << (pin.inner_connection.gate_r != nullptr ? std::to_string(pin.inner_connection.pin) : "N/A")
                  << std::setw(w) << TRI(pin.state)
                  << std::endl;
    }
}

void nts::ParentComponent::setName(const std::string &name)
{
    this->_name = name;
}

void nts::ParentComponent::setType(const std::string &type)
{
    this->_type = type;
}
