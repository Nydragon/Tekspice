/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include <fstream>
#include <iostream>
#include "GenericComponent.hpp"

nts::GenericComponent::GenericComponent(const std::string& type, const std::string &name)
{

    std::ifstream input_file("./resources/" + type + ".cfg");

    if (!input_file.is_open())
        exit(84);

    std::string content = std::string(std::istreambuf_iterator<char>(input_file), std::istreambuf_iterator<char>());
    std::cout << content;
}
