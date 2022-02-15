/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "XnorGate.hpp"

nts::Tristate nts::XnorGate::getInput1() {
    return this->_input1;
}
    
nts::Tristate nts::XnorGate::getInput2() {
    return this->_input2;
}

nts::Tristate nts::XnorGate::getOutput() {
    return _output;
}

void nts::XnorGate::setInput1(nts::Tristate Value) {
    this->_input1 = Value;
}

void nts::XnorGate::setInput2(nts::Tristate Value) {
    this->_input2 = Value;
}

void nts::XnorGate::setOutput(nts::Tristate Value) {
    this->_output = Value;
}

nts::Tristate nts::XnorGate::compute()
{
    if (getInput1() == TRUE && getInput2() == TRUE)
        setOutput(nts::Tristate::TRUE);
    else if (getInput1() == FALSE && getInput2() == FALSE)
        setOutput(nts::Tristate::TRUE);
    else
        setOutput(nts::Tristate::FALSE);
    return getOutput();
}
