/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#ifndef B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_SPLITTERGATE_HPP
#define B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_SPLITTERGATE_HPP

#include "GenericGate.hpp"

namespace nts
{
    class SplitterGate : virtual public GenericGate
    {
    public:
        explicit SplitterGate(const std::string &_name);

        ~SplitterGate() override = default;

        nts::Tristate compute() override;

        std::vector<nts::pin_t *> outputPins() override;
    };
};
#endif //B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_SPLITTERGATE_HPP
