/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#ifndef B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_EXECUTION_HPP
#define B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_EXECUTION_HPP

#include <string>

class Execution {
    public:
        Execution();
        ~Execution(){};
        std::string getValue();
        void setValue(std::string NewValue);
    private:
        std::string _value;
};

#endif //B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_EXECUTION_HPP
