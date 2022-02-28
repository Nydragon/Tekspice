/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#ifndef B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_PARENTCOMPONENT_HPP
#define B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_PARENTCOMPONENT_HPP

#include <vector>
#include "../IComponent.hpp"
#include "../types.hpp"

namespace nts
{
    class ParentComponent : public virtual IComponent
    {
    protected:

        ParentComponent(const std::string &name, const std::string &type);

        std::string _name;

        std::string _type;

        std::vector<pin_t> pins;

        virtual std::string getName() const;

        virtual std::string getType() const;

        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;

        virtual int findPinIndex(size_t pin) const;

        void dump() const override;

    };
}

#endif //B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_PARENTCOMPONENT_HPP
