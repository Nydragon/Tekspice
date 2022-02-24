/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "OrGate.hpp"

nts::OrGate::OrGate(std::string name) : GenericGate(name)
{
}

nts::Tristate nts::OrGate::compute()
{
    if (getInput1() == TRUE || getInput2() == TRUE)
        setOutput(nts::Tristate::TRUE);
    else
        setOutput(nts::Tristate::FALSE);
    return getOutput();
}
