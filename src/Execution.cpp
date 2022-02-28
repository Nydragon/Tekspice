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
#include "LogicGates/Gates.hpp"
#include "Components/GenericComponent.hpp"

Execution::Execution(const std::string &filename)
{
    this->loadFile(filename);
}

std::string Execution::getValue()
{
    return this->_value;
}

void Execution::setValue(const std::string &value)
{
    this->_value = value;
}

void Execution::display()
{
    std::cout << "tick: " << this->_tick << std::endl;
    std::cout << "input(s):" << std::endl;
    for (auto const &pair: this->_inputs)
        std::cout << "  " << pair.first << ": " << TRI(pair.second->getState()) << std::endl;
    std::cout << "output(s):" << std::endl;
    for (auto const &pair: this->_outputs)
        std::cout << "  " << pair.first << ": " << TRI(pair.second->getState()) << std::endl;
}

void Execution::input(const std::string &value)
{
    std::regex a("[a-zA-Z][a-zA-Z0-9_]*");
    std::regex b("-?\\d+");

    std::smatch match;

    std::string buffString;
    nts::Tristate newState;

    if (std::regex_search(ALL(value), match, a) == 1)
        buffString = match[0];
    if (buffString.empty() || !this->_inputs.contains(buffString))
        throw nts::NanoTekSpiceError("Input \"" + buffString + "\" does not exist.");
    if (std::regex_search(ALL(value), match, b) == 1) {
        if (match[0] == "1")
            newState = nts::Tristate::TRUE;
        else if (match[0] == "0")
            newState = nts::Tristate::FALSE;
        else if (match[0] == "-1")
            newState = nts::Tristate::UNDEFINED;
        else
            throw nts::NanoTekSpiceError("Left hand of assignment operator should be 1 or 0.");
    }

    this->_inputs[buffString]->setState(newState);
}

void Execution::simulate()
{

    this->_tick++;
    for (auto i: this->_inputs)
        i.second->simulate(this->_tick);

    for (const auto &i: this->circuitry)
        i.second->simulate(this->_tick);
    for (const auto &i: this->circuitry)
        i.second->simulate(this->_tick);
}

//{
//this->_tick++;
//
//for (auto i: this->_inputs)
//i.second->simulate(this->_tick);
//
//int outputEmpty = 1;
//
//while (outputEmpty) {
//outputEmpty = 0;
//for (const auto &i: this->circuitry)
//i.second->simulate(this->_tick);
//for (const auto &i: this->_outputs) {
//if (*i.second->getState() == nts::Tristate::UNDEFINED)
//outputEmpty = 1;
//}
//}

void Execution::loop()
{
    while (true) {
        try {
            this->simulate();
            this->display();
            sleep(1);
        } catch (...) {
            break;
        }
    }
}

void Execution::dump()
{
    for (const auto &component: this->circuitry) {
        component.second->dump();
    }
}

int Execution::isInputAssignment(const std::string &line)
{
    std::regex a("[[:alpha:]][[:alpha:]0-9_]*=-?\\d+");
    std::smatch match;

    return std::regex_search(ALL(line), match, a);
}

void Execution::run()
{
    std::string line;
    while (true) {
        try {
            std::cout << "> ";
            getline(std::cin, line);
            this->setValue(line);
            if (getValue() == "exit" || line.empty())
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
        if (line.empty())
            continue;
        if (line[0] == '.') {
            if (line == ".chipsets:") {
                section = 1;
            } else if (line == ".links:")
                section = 2;
            continue;
        }

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
            if (this->circuitry.contains(right))
                throw nts::NameUsedError(right);
            if (left == "input") {
                auto input = new nts::InputComponent(right);
                this->circuitry[right] = input;
                this->_inputs[right] = input;
            } else if (left == "output") {
                auto output = new nts::OutputComponent(right);
                this->circuitry[right] = output;
                this->_outputs[right] = output;
            } else if (left == "clock")
                TODO("clock component");
            else if (left == "true")
                TODO("true component");
            else if (left == "false")
                TODO("false component");
            else
                this->circuitry[right] = new nts::GenericComponent(left, right);
        }

        if (section == 2) {
            const auto beforeCol = std::regex(".+(?=:)");
            const auto afterCol = std::regex(":.+");
            std::string compNameLeft = std::regex_token_iterator(C_ALL(left), beforeCol, 0)->str();
            std::string compNameRight = std::regex_token_iterator(C_ALL(right), beforeCol, 0)->str();
            /**
             * I need to exclude the colon from the match but
             * \K and lookbehind do not work in c++ regex flavour
             * therefore I skip the first character of the match
             */
            size_t pinNumLeft = std::stoi(&std::regex_token_iterator(C_ALL(left), afterCol, 0)->str()[1]);
            size_t pinNumRight = std::stoi(&std::regex_token_iterator(C_ALL(right), afterCol, 0)->str()[1]);

            this->circuitry[compNameLeft]->setLink(pinNumLeft, *this->circuitry[compNameRight], pinNumRight);
        }
    }
}

std::unique_ptr<nts::IComponent> Execution::createComponent(const std::string &type)
{
    return std::unique_ptr<nts::IComponent>(new nts::GenericComponent(type, type + std::to_string(random() % 100000)));
}

Execution::~Execution()
{
    for (const auto& c: this->circuitry)
        delete c.second;
}
