/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include <iostream>
#include "AndGate.hpp"

nts::AndGate::AndGate(std::string name) : GenericGate(name)
{
}

nts::Tristate nts::AndGate::compute()
{
    if (getInput1() == TRUE && getInput2() == TRUE)
        setOutput(nts::Tristate::TRUE);
    else
        setOutput(nts::Tristate::FALSE);
    return getOutput();
}
