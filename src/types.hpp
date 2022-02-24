/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#ifndef B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_TYPES_HPP
#define B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_TYPES_HPP
#define KOWALSKI std::cout << "Kowalski, analysis." << std::endl;
#define C_ALL(a) cbegin(a), cend(a)

#include <cstddef>

namespace nts
{
    class ILogicGate;
    class IComponent;

    typedef struct
    {
        size_t pin = 0;
        IComponent *comp_r = nullptr;
    } componentConnection;

    typedef struct
    {
        size_t pin = 0;
        ILogicGate *gate_r = nullptr;
    } logicGateConnection;

    typedef struct
    {
        size_t number = 0;
        nts::Tristate state = nts::Tristate::UNDEFINED;
        componentConnection outer_connection = componentConnection();
        logicGateConnection inner_connection = logicGateConnection();
    } pin_t;
}
#endif //B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_TYPES_HPP
