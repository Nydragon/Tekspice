/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "XnorGate.hpp"

nts::XnorGate::XnorGate(std::string name) : GenericGate(name) {}

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
