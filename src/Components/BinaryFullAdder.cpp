/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "BinaryFullAdder.hpp"

void nts::BinaryFullAdder::simulate(std::size_t tick)
{
    this->_tick = tick;
    // a
    nts::Tristate n1_1 = *this->pins[this->findPinIndex(7)].state;
    nts::Tristate n1_2 = *this->pins[this->findPinIndex(5)].state;
    nts::Tristate n1_3 = *this->pins[this->findPinIndex(3)].state;
    nts::Tristate n1_4 = *this->pins[this->findPinIndex(1)].state;

    // b
    nts::Tristate n2_1 = *this->pins[this->findPinIndex(6)].state;
    nts::Tristate n2_2 = *this->pins[this->findPinIndex(4)].state;
    nts::Tristate n2_3 = *this->pins[this->findPinIndex(2)].state;
    nts::Tristate n2_4 = *this->pins[this->findPinIndex(15)].state;

    nts::Tristate in_c = *this->pins[this->findPinIndex(9)].state;

    int n1[] = {n1_1, n1_2, n1_3, n1_4};
    int n2[] = {n2_1, n2_2, n2_3, n2_4};

    int n1binary = 0;
    int n2binary = 0;

    int mul = 1;
    for (int i = 0; i < 5; i++) {
        n1binary += (n1[i] * mul);
        n2binary += (n2[i] * mul);
        mul *= 2;
    }
    int result = n1binary + n2binary;
    nts::Tristate binaryNumber[5] = {nts::Tristate::FALSE, nts::Tristate::FALSE, nts::Tristate::FALSE, nts::Tristate::FALSE,
                                     nts::Tristate::FALSE};

    int i = 0;
    while (result > 0) {
        binaryNumber[i] = result % 2 == 1 ? nts::Tristate::TRUE : nts::Tristate::FALSE;
        result = result / 2;
        i++;
    }
    *this->pins[this->findPinIndex(10)].state = binaryNumber[0];
    *this->pins[this->findPinIndex(11)].state = binaryNumber[1];
    *this->pins[this->findPinIndex(12)].state = binaryNumber[2];
    *this->pins[this->findPinIndex(13)].state = binaryNumber[3];
    *this->pins[this->findPinIndex(14)].state = binaryNumber[4];

}

nts::BinaryFullAdder::BinaryFullAdder(const std::string &name)
    : ParentComponent(name, "4008")
{
    this->_pin_no = 16;
    this->pins.resize(this->_pin_no);

    for (size_t i = 0; i < this->_pin_no; i++) {
        this->pins[i] = {.number =  i + 1, .state = std::make_unique<nts::Tristate>(nts::Tristate::UNDEFINED)};
    }
    this->_tick = 0;
}

nts::Tristate nts::BinaryFullAdder::compute(std::size_t pin)
{
    return nts::FALSE;
}

nts::BinaryFullAdder::~BinaryFullAdder()
{
}
