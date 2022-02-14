/*
** EPITECH PROJECT, $Year
** Project
** File description:
** Description
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int errorArg(std::string arg)
{
    string filecontent; 
    ifstream input_file(arg);

    if (arg == "-h") {
        cout << "Enter a filename in param : ./nanotekspice [filename]" << endl;
        return (0);
    }
    if (!input_file.is_open())
        return (84);
    filecontent = string((std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>());
    cout << filecontent;
    return 0;
}

int main(int argc, char *argv[])
{
    //if (argc != 2)
    //    return 84;
    //if (errorArg(argv[1]) == 84)
    //    return 84;

    return 0;
}
