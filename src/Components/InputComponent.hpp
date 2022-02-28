/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#ifndef B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_INPUTCOMPONENT_HPP
#define B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_INPUTCOMPONENT_HPP

#include <vector>
#include "../IComponent.hpp"
#include "../types.hpp"
#include "ParentComponent.hpp"

namespace nts
{
    class InputComponent : public virtual ParentComponent
    {
        size_t _pin_no = 1;

        std::size_t _tick = 0;

        nts::Tristate *_state;
    public:
        explicit InputComponent(const std::string &name, nts::Tristate state = nts::Tristate::UNDEFINED);

        ~InputComponent() override = default;

        void simulate(std::size_t tick) override;

        nts::Tristate compute(std::size_t pin) override;

        void setState(nts::Tristate state);

        nts::Tristate* getState() const;
    };
}

#endif //B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_INPUTCOMPONENT_HPP
