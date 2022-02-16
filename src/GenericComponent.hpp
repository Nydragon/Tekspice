/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#ifndef B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_GENERICCOMPONENT_HPP
#define B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_GENERICCOMPONENT_HPP

#include <string>
#include <vector>
#include <deque>
#include <unordered_map>
#include "IComponent.hpp"
#include "ILogicGate.hpp"

namespace nts
{
    class GenericComponent : public virtual IComponent
    {
        std::string _name;

        std::vector<ILogicGate *> circuitry;

        std::vector<std::deque<std::size_t>> pins;
        //  [Output Pin, Input Pin 1, Input Pin 2]
        //  For 4081 Four And Gate:
        //  [
        //      [3, 1, 2]
        //      [4, 5, 6]
        //      [10, 8, 9]
        //      [11, 12, 13]
        //  ]

    public:
        GenericComponent(const std::string &type, const std::string &name);

        ~GenericComponent() = default;

        void simulate(std::size_t tick);

        nts::Tristate compute(std::size_t pin) override;

        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);

        void dump() const override;

        static ILogicGate *fetchGate(const std::string &type, const std::string &name);

        int findGateIndex(const std::string &name);
    };
}

#endif //B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_GENERICCOMPONENT_HPP
