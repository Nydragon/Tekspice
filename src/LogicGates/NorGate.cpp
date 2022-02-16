/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "NorGate.hpp"

nts::NorGate::NorGate(std::string name) : GenericGate(name) {}

nts::Tristate nts::NorGate::compute()
{
    if (getInput1() == FALSE && getInput2() == FALSE)
        setOutput(nts::Tristate::TRUE);
    else
        setOutput(nts::Tristate::FALSE);
    return getOutput();
}
