/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "NandGate.hpp"

nts::Tristate nts::NandGate::getInput1() {
    return this->_input1;
}
    
nts::Tristate nts::NandGate::getInput2() {
    return this->_input2;
}

nts::Tristate nts::NandGate::getOutput() {
    return _output;
}

void nts::NandGate::setInput1(nts::Tristate Value) {
    this->_input1 = Value;
}

void nts::NandGate::setInput2(nts::Tristate Value) {
    this->_input2 = Value;
}

void nts::NandGate::setOutput(nts::Tristate Value) {
    this->_output = Value;
}

nts::Tristate nts::NandGate::compute()
{
    if (getInput1() == TRUE && getInput2() == TRUE)
        setOutput(nts::Tristate::FALSE);
    else
        setOutput(nts::Tristate::TRUE);
    return getOutput();
}
