/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "XorGate.hpp"

nts::Tristate nts::XorGate::getInput1() {
    return this->_input1;
}
    
nts::Tristate nts::XorGate::getInput2() {
    return this->_input2;
}

nts::Tristate nts::XorGate::getOutput() {
    return _output;
}

void nts::XorGate::setInput1(nts::Tristate Value) {
    this->_input1 = Value;
}

void nts::XorGate::setInput2(nts::Tristate Value) {
    this->_input2 = Value;
}

void nts::XorGate::setOutput(nts::Tristate Value) {
    this->_output = Value;
}

nts::Tristate nts::XorGate::compute()
{
    if (getInput1() == TRUE && getInput2() == TRUE)
        setOutput(nts::Tristate::FALSE);
    else if (getInput1() == FALSE && getInput2() == FALSE)
        setOutput(nts::Tristate::FALSE);
    else
        setOutput(nts::Tristate::TRUE);
    return getOutput();
}
