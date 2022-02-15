/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#ifndef B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_ORGATE_HPP
#define B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_ORGATE_HPP
#include "../IComponent.hpp"
#include "../ILogicGate.hpp"


namespace nts {
    class OrGate: virtual public ILogicGate
    {
        public:
            OrGate() = default;
            ~OrGate() = default;
            nts::Tristate compute();
            nts::Tristate getInput1();
            nts::Tristate getInput2();
            nts::Tristate getOutput();
            void setInput1(nts::Tristate);
            void setInput2(nts::Tristate);
            void setOutput(nts::Tristate);
        private:
            nts::Tristate _input1 = nts::Tristate::UNDEFINED;
            nts::Tristate _input2 = nts::Tristate::UNDEFINED;
            nts::Tristate _output = nts::Tristate::UNDEFINED;
    };
};

#endif //B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_ORGATE_HPP
