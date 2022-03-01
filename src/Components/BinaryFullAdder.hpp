/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#ifndef B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_BINARYFULLADDER_HPP
#define B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_BINARYFULLADDER_HPP

#include "ParentComponent.hpp"

namespace nts
{
    class BinaryFullAdder : public virtual ParentComponent
    {
        std::size_t _pin_no = 1;

        std::size_t _tick = 0;
    public:
        explicit BinaryFullAdder(const std::string &name);

        ~BinaryFullAdder() override;

        void simulate(std::size_t tick) override;

        nts::Tristate compute(std::size_t pin) override;
    };
}

#endif //B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_BINARYFULLADDER_HPP
