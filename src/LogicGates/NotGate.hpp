/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#ifndef B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_NOTGATE_HPP
#define B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_NOTGATE_HPP
#include "../IComponent.hpp"
#include "../ILogicGate.hpp"
#include <string>

namespace nts {
    class NotGate: virtual public ILogicGate
    {
        public:
            NotGate(std::string name);
            ~NotGate() = default;
            nts::Tristate compute();
            nts::Tristate getInput1();
            nts::Tristate getOutput();
            std::string getName();
            void setInput1(nts::Tristate);
            void setOutput(nts::Tristate);
        private:
            nts::Tristate _input1 = nts::Tristate::UNDEFINED;
            nts::Tristate _output = nts::Tristate::UNDEFINED;
            std::string _name;
    };
};

#endif //B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_NOTGATE_HPP
