/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "NorGate.hpp"

nts::Tristate nts::NorGate::getInput1() {
    return this->_input1;
}
    
nts::Tristate nts::NorGate::getInput2() {
    return this->_input2;
}

nts::Tristate nts::NorGate::getOutput() {
    return _output;
}

void nts::NorGate::setInput1(nts::Tristate Value) {
    this->_input1 = Value;
}

void nts::NorGate::setInput2(nts::Tristate Value) {
    this->_input2 = Value;
}

void nts::NorGate::setOutput(nts::Tristate Value) {
    this->_output = Value;
}

nts::Tristate nts::NorGate::compute()
{
    if (getInput1() == FALSE && getInput2() == FALSE)
        setOutput(nts::Tristate::TRUE);
    else
        setOutput(nts::Tristate::FALSE);
    return getOutput();
}
