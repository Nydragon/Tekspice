/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#ifndef B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_NANOTEKSPICEERROR_HPP
#define B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_NANOTEKSPICEERROR_HPP

#include <string>

#pragma once

namespace nts
{
    class NanoTekSpiceError : public std::exception
    {
        std::string _message;
        std::string _component;

    public:
        explicit NanoTekSpiceError(std::string const &message);

        std::string const &getComponent() const;

        const char *what() const noexcept override;
    };

    class FileNotFound : public NanoTekSpiceError
    {
    public:
        explicit FileNotFound(const std::string &path);
    };

    class InvalidLink : public NanoTekSpiceError
    {
    public:
        InvalidLink(const std::string &type, const std::string &line);
    };

    class SyntaxError : public NanoTekSpiceError
    {
    public:
        explicit SyntaxError(const std::string &line, int line_no);
    };

    class NameUsedError : public NanoTekSpiceError
    {
    public:
        explicit NameUsedError(const std::string &name);
    };

    class PinNotFoundError : public NanoTekSpiceError
    {
    public:
        explicit PinNotFoundError(const std::string &name, size_t pin);
    };

    class EmptyCircuitryError : public NanoTekSpiceError
    {
    public:
        explicit EmptyCircuitryError();
    };

    class ComponentNotFoundError : public NanoTekSpiceError
    {
    public:
        explicit ComponentNotFoundError(const std::string &name);
        explicit ComponentNotFoundError(const std::string &name, int line_number);
    };

    class FileFormatError : public NanoTekSpiceError
    {
    public:
        explicit FileFormatError(const std::string &path);
    };


    void validateArgs(int count, char *args_c[]);
}

#endif //B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_NANOTEKSPICEERROR_HPP
