/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "NandGate.hpp"

nts::NandGate::NandGate(std::string name) : GenericGate(name) {}

nts::Tristate nts::NandGate::compute()
{
    if (getInput1() == TRUE && getInput2() == TRUE)
        setOutput(nts::Tristate::FALSE);
    else
        setOutput(nts::Tristate::TRUE);
    return getOutput();
}
