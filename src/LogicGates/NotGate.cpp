/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "NotGate.hpp"

nts::NotGate::NotGate(const std::string &name) : GenericGate(name)
{
}

nts::Tristate nts::NotGate::compute()
{
    if (getInput1() == TRUE)
        setOutput(nts::Tristate::FALSE);
    else
        setOutput(nts::Tristate::TRUE);
    return getOutput();
}

nts::pin_t &nts::NotGate::outputPin()
{
    return this->pins[1];
}
