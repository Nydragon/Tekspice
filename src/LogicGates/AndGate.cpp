/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "AndGate.hpp"

nts::Tristate nts::AndGate::getInput1()
{
    return this->_input1;
}

nts::Tristate nts::AndGate::getInput2()
{
    return this->_input2;
}

nts::Tristate nts::AndGate::getOutput()
{
    return _output;
}

void nts::AndGate::setInput1(nts::Tristate Value)
{
    this->_input1 = Value;
}

void nts::AndGate::setInput2(nts::Tristate Value)
{
    this->_input2 = Value;
}

void nts::AndGate::setOutput(nts::Tristate Value)
{
    this->_output = Value;
}

nts::Tristate nts::AndGate::compute()
{
    if (getInput1() == TRUE && getInput2() == TRUE)
        setOutput(nts::Tristate::TRUE);
    else
        setOutput(nts::Tristate::FALSE);
    return getOutput();
}

std::string nts::AndGate::getName()
{
    return this->_name;
}
