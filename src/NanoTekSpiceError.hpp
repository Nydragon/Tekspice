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
}

#endif //B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_NANOTEKSPICEERROR_HPP
