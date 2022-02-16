/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "XorGate.hpp"

nts::XorGate::XorGate(std::string name) : GenericGate(name) {}

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
