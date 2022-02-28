/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "NotNotGate.hpp"

nts::NotNotGate::NotNotGate(std::string name)
    : GenericGate(name)
{
}

std::string nts::NotNotGate::getName()
{
    return this->_name;
}

nts::Tristate nts::NotNotGate::getInput1()
{
    return this->_input1;
}

nts::Tristate nts::NotNotGate::getOutput()
{
    return this->_output;
}

void nts::NotNotGate::setInput1(nts::Tristate Value)
{
    this->_input1 = Value;
}

void nts::NotNotGate::setOutput(nts::Tristate Value)
{
    this->_output = Value;
}

nts::Tristate nts::NotNotGate::compute()
{
    if (getInput1() == TRUE)
        setOutput(nts::Tristate::TRUE);
    else
        setOutput(nts::Tristate::FALSE);
    return getOutput();
}
