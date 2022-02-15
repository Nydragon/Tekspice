/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#ifndef B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_ICOMPONENT_HPP
#define B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_ICOMPONENT_HPP

#include <cstddef>

namespace nts
{

    static std::string componentCfgLocation = "src/resources/";

    enum Tristate
    {
        UNDEFINED = (-true),
        TRUE = true,
        FALSE = false
    };

    class IComponent
    {
    public:
        virtual ~ IComponent() = default;

        virtual void simulate(std::size_t tick) = 0;

        virtual nts::Tristate compute(std::size_t pin) = 0;

        virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;

        virtual void dump() const = 0;
    };
}

#endif //B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_ICOMPONENT_HPP
