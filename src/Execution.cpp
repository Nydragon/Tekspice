/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include <fstream>
#include "Execution.hpp"
#include "NanoTekSpiceError.hpp"
#include "types.hpp"

Execution::Execution(const std::string &filename)
{
    this->loadFile(filename);
}

std::string Execution::getValue()
{
    return this->_value;
}

void Execution::display()
{
    int a = 1;
    std::cout << "tick: " << a << std::endl;
    std::cout << "input(s):" << std::endl;
    for (auto const &pair: this->_inputs)
        std::cout << "  " << pair.first << ": " << pair.second << std::endl;
    std::cout << "output(s):\n  s: 0" << std::endl;
}

void Execution::input(std::string value)
{
    std::regex a("[a-zA-Z][a-zA-Z0-9]*");
    std::regex b("-?[01]");

    std::smatch match;
    const std::string gValue = value;

    std::string buffString = "default";
    nts::Tristate buffValue = nts::Tristate::FALSE;
    if (std::regex_search(gValue.begin(), gValue.end(), match, a) == 1)
        buffString = match[0];
    if (std::regex_search(gValue.begin(), gValue.end(), match, b) == 1) {
        if (match[0] == "1")
            buffValue = nts::Tristate::TRUE;
        else if (match[0] == "0")
            buffValue = nts::Tristate::FALSE;
        else
            buffValue = nts::Tristate::UNDEFINED;
    }

    this->_inputs[buffString] = buffValue;
}

void Execution::simulate()
{
    std::cout << "simulate g" << std::endl;
}

void Execution::loop()
{
    std::cout << "loop g" << std::endl;
}

void Execution::dump()
{
    std::cout << "dump g" << std::endl;
}

void Execution::nobody()
{

    std::cout << "nobody g" << std::endl;
}

void Execution::run()
{

    std::regex a("[[:alpha:]0-9]*=-?[01]");
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
            input(this->_value);
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

void Execution::loadFile(const std::string &filename)
{
    std::ifstream input_file(filename);

    if (!input_file.is_open())
        throw nts::FileNotFound(filename);

    std::string line;
    const auto r = std::regex(R"(.*?(?=(#|$)))");
    int section = 99;

    while (std::getline(input_file, line)) {
        line = std::regex_token_iterator(C_ALL(line), r, 0)->str();

        if (line[0] == '.') {
            if (line == ".chipsets:") {
                section = 1;
            } else if (line == ".links:")
                section = 2;
            continue;
        }

        std::cout << line << std::endl;

        char *token = std::strtok(const_cast<char *>(std::string(line).c_str()), " ");

        std::cout << "token " << token << std::endl;
        std::string left;
        std::string right;

        left =  std::string(token);
        std::cout << "string " << left << std::endl;
        if ((token = std::strtok(nullptr, " ")))
            right = std::string(token);

        if (section == 1) {
            if (left == "input") {
                this->_inputs[right] = nts::Tristate::UNDEFINED;
            }
        }
    }
}
