/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#ifndef B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_TRUECOMPONENT_HPP
#define B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_TRUECOMPONENT_HPP

#include "ParentComponent.hpp"

namespace nts
{
    class TrueComponent : public virtual ParentComponent
    {
        std::size_t _pin_no = 1;

        std::size_t _tick = 0;

        nts::Tristate *_state;
    public:
        explicit TrueComponent(const std::string &name);

        ~TrueComponent() override;

        void simulate(std::size_t tick) override;

        nts::Tristate compute(std::size_t pin) override;

        void setState(nts::Tristate state);

        nts::Tristate *getState() const;
    };
}

#endif //B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_TRUECOMPONENT_HPP
