/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "Execution.hpp"

Execution::Execution() {}

std::string Execution::getValue() {
    return this->_value;
}

void Execution::display() {
    std::cout << "display g" << std::endl;
}

void Execution::input() {
    std::cout << "input g" << std::endl;
}

void Execution::simulate() {
    std::cout << "simulate g" << std::endl;
}

void Execution::loop() {
    std::cout << "loop g" << std::endl;   
}

void Execution::dump() {
    std::cout << "dump g" << std::endl;
}

void Execution::nobody() {
    
    std::cout << "nobody g" << std::endl;
}

void Execution::run() {
    
    std::regex a("[[:alpha:]0-9]*=[01]");
    std::smatch match;
    
    while (true) {
        std::cout << "> ";
        getline(std::cin, this->_value);
        const std::string test = this->_value;
        if (getValue() == "exit")
            break;
        else if (getValue() == "display")
            display();
        else if (std::regex_search(test.begin(), test.end(), match, a))
            input();
        else if (getValue() == "simulate")
            simulate();
        else if (getValue() == "loop")
            loop();
        else if (getValue() == "dump")
            dump();
        else
            nobody();
    }
}

//int main() {
//    Execution l;
//    l.run();
//    return 0;
//}