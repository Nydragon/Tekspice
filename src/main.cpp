/*
** EPITECH PROJECT, $Year
** Project
** File description:
** Description
*/

#include <string>
#include <memory>
#include "Components/GenericComponent.hpp"
#include "Execution.hpp"
#include "NanoTekSpiceError.hpp"

std::unique_ptr<nts::IComponent> createComponent(const std::string &type)
{
    return std::unique_ptr<nts::IComponent>(new nts::GenericComponent(type, type + std::to_string(random() % 100000)));
};

int main(int argc, char *argv[])
{
    nts::validateArgs(argc, argv);

    auto cli = new Execution(argv[1]);
    cli->run();
    delete cli;

    return 0;
}
