/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#ifndef B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_EXECUTION_HPP
#define B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_EXECUTION_HPP

#include <string>
#include <iostream>
#include <map>
#include <regex>
#include <unordered_map>
#include "IComponent.hpp"

class Execution
{
public:
    explicit Execution(const std::string &filename);

    ~Execution() = default;

    std::string getValue();

    void setValue(const std::string &value);

    void run();

    // function dispo
    void display();

    void input(const std::string &value);

    void simulate();

    void loop();

    void dump();

    void loadFile(const std::string &filename);

    static int isInputAssignment(const std::string &);

private:
    int _loop = 1;
    std::string _value;
    std::deque<nts::IComponent *> circuitry;
    std::unordered_map<std::string, nts::Tristate> _inputs;
    std::unordered_map<std::string, nts::Tristate> _outputs;
};

#endif //B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_EXECUTION_HPP
