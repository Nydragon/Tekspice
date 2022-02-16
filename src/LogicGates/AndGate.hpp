/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#ifndef B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_ANDGATE_HPP
#define B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_ANDGATE_HPP
#include "../IComponent.hpp"
#include "GenericGate.hpp"

namespace nts {
    class AndGate: virtual public GenericGate
    {
        public:
            AndGate(std::string _name);
            ~AndGate() = default;
            nts::Tristate compute();
    };
};

#endif //B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_ANDGATE_HPP
