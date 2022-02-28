/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#ifndef B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_TYPES_HPP
#define B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_TYPES_HPP

#include <cstddef>
#include <iostream>
#include <memory>

#define KOWALSKI (std::cout << "Kowalski, analysis." << std::endl);
#define C_ALL(a) cbegin(a), cend(a)
#define ALL(a) begin(a), end(a)
#define TODO(a) do { \
    std::cout << "NOT IMPLEMENTED: " << a << std::endl; \
    std::cout << "line "<< __LINE__  << " | " << __func__ << "() | " << __FILE__ << std::endl; \
} while(0)

#define TRI(state) ((*state) == nts::Tristate::UNDEFINED ? "U" : std::to_string((*state)))

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
        std::shared_ptr<nts::Tristate> state = std::make_shared<nts::Tristate>();
        componentConnection outer_connection = componentConnection();
        logicGateConnection inner_connection = logicGateConnection();
    } pin_t;
}
#endif //B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_TYPES_HPP
