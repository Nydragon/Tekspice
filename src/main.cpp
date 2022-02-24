/*
** EPITECH PROJECT, $Year
** Project
** File description:
** Description
*/

#include <iostream>
#include <string>
#include <fstream>
#include <memory>
#include "GenericComponent.hpp"
#include <time.h>

int errorArg(std::string arg)
{
    std::string filecontent;
    std::ifstream input_file(arg);

    if (arg == "-h") {
        std::cout << "Enter a filename in param : ./nanotekspice [filename]" << std::endl;
        return (0);
    }
    if (!input_file.is_open())
        return (84);
    filecontent = std::string((std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>());
    std::cout << filecontent;
    return 0;
}

std::unique_ptr<nts::IComponent> createComponent(const std::string &type)
{
    return std::unique_ptr<nts::IComponent>(new nts::GenericComponent(type, std::to_string(random() % 100000)));
};

//int main(int argc, char *argv[])
//{
//    if (argc != 2)
//        return 84;
//    if (errorArg(argv[1]) == 84)
//        return 84;
//    // std::cout << "Hello, World!" << std::endl;
//    return 0;
//}

int main()
{
    srandom(time(0));

    try {

        //        auto comp = new nts::GenericComponent("4071", "or");
        //
        //        comp->pins[0].state = nts::Tristate::TRUE;
        //        comp->pins[1].state = nts::Tristate::FALSE;
        //
        //        comp->simulate(1);
        //
        //        comp->dump();


        //                auto and1 = createComponent("4081");
        //
        //                auto and2 = createComponent("4081");
        //
        //                and1->dump();
        //
        //                and1->setLink(1, *and2, 3);

        auto comp = new nts::GenericComponent("4081", "and");

        comp->pins[0].state = nts::Tristate::TRUE;
        comp->pins[1].state = nts::Tristate::TRUE;

        comp->simulate(1);

        comp->dump();

        //                and1->dump();
        //                and2->dump();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "test";

    return 0;
}
