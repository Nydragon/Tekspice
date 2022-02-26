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
    std::cout << "output(s):" << std::endl;
    for (auto const &pair: this->_outputs)
        std::cout << "  " << pair.first << ": " << pair.second << std::endl;
}

void Execution::input(const std::string &value)
{
    std::regex a("[a-zA-Z][a-zA-Z0-9]*");
    std::regex b("-?\\d+");

    std::smatch match;

    std::string buffString;
    nts::Tristate buffValue;

    if (std::regex_search(ALL(value), match, a) == 1)
        buffString = match[0];
    if (buffString.empty() || !this->_inputs.contains(buffString))
        throw nts::NanoTekSpiceError("Input \"" + buffString + "\" does not exist.");
    if (std::regex_search(ALL(value), match, b) == 1) {
        if (match[0] == "1")
            buffValue = nts::Tristate::TRUE;
        else if (match[0] == "0")
            buffValue = nts::Tristate::FALSE;
        else if (match[0] == "-1")
            buffValue = nts::Tristate::UNDEFINED;
        else
            throw nts::NanoTekSpiceError("Left hand of assignment operator should be 1 or 0.");
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

int Execution::isInputAssignment(const std::string &line)
{
    std::regex a("[[:alpha:]][[:alpha:]0-9]*=-?\\d+");
    std::smatch match;

    return std::regex_search(ALL(line), match, a);
}

void Execution::run()
{

    while (true) {
        try {
            std::cout << "> ";
            getline(std::cin, this->_value);
            if (getValue() == "exit")
                break;
            else if (getValue() == "display")
                display();
            else if (this->isInputAssignment(this->_value))
                this->input(this->_value);
            else if (getValue() == "simulate")
                simulate();
            else if (getValue() == "loop")
                loop();
            else if (getValue() == "dump")
                dump();
            else
                throw nts::NanoTekSpiceError("Invalid Command: \"" + this->_value + "\"");
        } catch (std::exception &err) {
            std::cerr << err.what() << std::endl;
        }
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

    int line_no = 0;

    while (std::getline(input_file, line)) {
        line_no++;
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

        if (!token)
            throw nts::SyntaxError(line, line_no);
        std::string left = std::string(token);
        std::string right;
        if ((token = std::strtok(nullptr, " ")))
            right = std::string(token);
        else
            throw nts::SyntaxError(line, line_no);

        if (section == 1) {
            if (left == "input")
                this->_inputs[right] = nts::Tristate::UNDEFINED;
            if (left == "output")
                this->_outputs[right] = nts::Tristate::UNDEFINED;
        }
    }
}
