/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#ifndef B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_NORGATE_HPP
#define B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_NORGATE_HPP
#include "../IComponent.hpp"
#include "GenericGate.hpp"


namespace nts {
    class NorGate: virtual public GenericGate
    {
        public:
            NorGate(std::string _name);
            ~NorGate() = default;
            nts::Tristate compute();
    };
};

#endif //B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_NORGATE_HPP
