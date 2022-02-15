/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#ifndef B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_ILOGICGATE_HPP
#define B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_ILOGICGATE_HPP

#include "IComponent.hpp"

namespace nts
{
    class ILogicGate
    {
    public:
        virtual ~ILogicGate() = default;
        virtual nts::Tristate compute() = 0;
    };
}
#endif //B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_ILOGICGATE_HPP
