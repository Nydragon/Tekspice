/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#ifndef B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_XNORGATE_HPP
#define B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_XNORGATE_HPP
#include "../IComponent.hpp"
#include "GenericGate.hpp"


namespace nts {
    class XnorGate: virtual public GenericGate
    {
        public:
            XnorGate(std::string _name);
            ~XnorGate() = default;
            nts::Tristate compute();
    };
};

#endif //B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_XNORGATE_HPP
