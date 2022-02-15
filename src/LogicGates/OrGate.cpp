/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "OrGate.hpp"

nts::Tristate nts::OrGate::getInput1() {
    return this->_input1;
}
    
nts::Tristate nts::OrGate::getInput2() {
    return this->_input2;
}

nts::Tristate nts::OrGate::getOutput() {
    return _output;
}

void nts::OrGate::setInput1(nts::Tristate Value) {
    this->_input1 = Value;
}

void nts::OrGate::setInput2(nts::Tristate Value) {
    this->_input2 = Value;
}

void nts::OrGate::setOutput(nts::Tristate Value) {
    this->_output = Value;
}

nts::Tristate nts::OrGate::compute()
{
    if (getInput1() == FALSE && getInput2() == FALSE)
        setOutput(nts::Tristate::FALSE);
    else
        setOutput(nts::Tristate::TRUE);
    return getOutput();
}
