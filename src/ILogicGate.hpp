/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#ifndef B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_ILOGICGATE_HPP
#define B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_ILOGICGATE_HPP

#include <string>
#include "IComponent.hpp"

namespace nts
{
    class ILogicGate
    {
    public:
        virtual ~ILogicGate() = default;

        virtual nts::Tristate compute() = 0;

        virtual std::string getName() = 0;

        virtual int findPinIndex(size_t pin) const = 0;

        virtual void setLink(std::size_t pin, nts::ILogicGate &other, std::size_t otherPin) = 0;

        virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;

        virtual void dump() = 0;

        virtual nts::Tristate getInput1() = 0;

        virtual nts::Tristate getInput2() = 0;

        virtual nts::Tristate getOutput() = 0;

        virtual void setInput1(nts::Tristate) = 0;

        virtual void setInput2(nts::Tristate) = 0;

        virtual void setOutput(nts::Tristate) = 0;

        virtual void setPin(size_t pin, nts::Tristate state) = 0;
    };
}
#endif //B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_ILOGICGATE_HPP
