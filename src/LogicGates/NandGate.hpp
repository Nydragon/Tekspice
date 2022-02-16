/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#ifndef B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_NANDGATE_HPP
#define B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_NANDGATE_HPP
#include "../IComponent.hpp"
#include "GenericGate.hpp"


namespace nts {
    class NandGate: virtual public GenericGate
    {
        public:
            NandGate(std::string _name);
            ~NandGate() = default;
            nts::Tristate compute();
    };
};

#endif //B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_NANDGATE_HPP
