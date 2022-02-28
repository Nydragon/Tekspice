/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#ifndef B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_NOTGATE_HPP
#define B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_NOTGATE_HPP

#include "GenericGate.hpp"

namespace nts
{
    class NotGate : virtual public GenericGate
    {
    public:
        NotGate(const std::string &name);

        ~NotGate() = default;

        nts::Tristate compute();

        pin_t &outputPin() override;
    };
};

#endif //B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_NOTGATE_HPP
