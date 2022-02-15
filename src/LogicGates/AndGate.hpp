/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#ifndef B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_ANDGATE_HPP
#define B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_ANDGATE_HPP

#include <string>
#include "../ILogicGate.hpp"

namespace nts
{
    class AndGate : virtual public ILogicGate
    {
    public:
        std::string _name;

        AndGate(const std::string &name)
        {
            this->_name = name;
        };

        ~AndGate() = default;

        nts::Tristate compute();

        nts::Tristate getInput1();

        nts::Tristate getInput2();

        nts::Tristate getOutput();

        std::string getName();

        void setInput1(nts::Tristate);

        void setInput2(nts::Tristate);

        void setOutput(nts::Tristate);

    private:
        nts::Tristate _input1 = nts::Tristate::UNDEFINED;
        nts::Tristate _input2 = nts::Tristate::UNDEFINED;
        nts::Tristate _output = nts::Tristate::UNDEFINED;
    };
};

#endif //B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_ANDGATE_HPP
