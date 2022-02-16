/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "GenericGate.hpp"

nts::GenericGate::GenericGate(std::string name) {
    this->_name = name;
}

nts::Tristate nts::GenericGate::getInput1() {
    return this->_input1;
}

nts::Tristate nts::GenericGate::getInput2() {
    return this->_input2;
}

nts::Tristate nts::GenericGate::getOutput() {
    return this->_output;
}

std::string nts::GenericGate::getName() {
    return this->_name;
}

void nts::GenericGate::setInput1(nts::Tristate Value) {
    this->_input1 = Value;
}

void nts::GenericGate::setInput2(nts::Tristate Value) {
    this->_input2 = Value;
}

void nts::GenericGate::setOutput(nts::Tristate Value) {
    this->_output = Value;
}
