/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#ifndef B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_ORGATE_HPP
#define B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_ORGATE_HPP
#include "../IComponent.hpp"
#include "GenericGate.hpp"


namespace nts {
    class OrGate: virtual public GenericGate
    {
        public:
            OrGate(std::string _name);
            ~OrGate() = default;
            nts::Tristate compute();
    };
};

#endif //B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_ORGATE_HPP
