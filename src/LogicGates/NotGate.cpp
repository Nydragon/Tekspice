/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "NotGate.hpp"

nts::Tristate nts::NotGate::getInput1() {
    return this->_input1;
}

nts::Tristate nts::NotGate::getOutput() {
    return _output;
}

void nts::NotGate::setInput1(nts::Tristate Value) {
    this->_input1 = Value;
}

void nts::NotGate::setOutput(nts::Tristate Value) {
    this->_output = Value;
}

nts::Tristate nts::NotGate::compute()
{
    if (getInput1() == TRUE)
        setOutput(nts::Tristate::FALSE);
    else
        setOutput(nts::Tristate::TRUE);
    return getOutput();
}
