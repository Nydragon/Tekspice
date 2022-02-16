/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "OrGate.hpp"

nts::OrGate::OrGate(std::string name) : GenericGate(name) {}

nts::Tristate nts::OrGate::compute()
{
    if (getInput1() == FALSE && getInput2() == FALSE)
        setOutput(nts::Tristate::FALSE);
    else
        setOutput(nts::Tristate::TRUE);
    return getOutput();
}
