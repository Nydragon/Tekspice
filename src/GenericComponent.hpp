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
#include <unordered_map>
#include "IComponent.hpp"
#include "ILogicGate.hpp"

namespace nts
{
    class GenericComponent : public virtual IComponent
    {
        std::string name;

        std::vector<ILogicGate> circuitry;

        std::vector<std::vector<std::size_t>> pins;
//        [
//  [3, 1, 2]
//  [4, 5, 6]
//  [10, 8, 9]
//  [11, 12, 13]
//       ]


    public:
        GenericComponent(const std::string& type, const std::string& name);

        ~GenericComponent() = default;

        void simulate(std::size_t tick) = 0;

        nts::Tristate compute(std::size_t pin) = 0;

        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;

        void dump() const = 0;
    };
}

#endif //B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_GENERICCOMPONENT_HPP
