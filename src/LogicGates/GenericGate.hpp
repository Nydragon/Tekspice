/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#ifndef B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_GENGATE_HPP
#define B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_GENGATE_HPP

#include "../IComponent.hpp"
#include "../ILogicGate.hpp"
#include "../GenericComponent.hpp"
#include <string>

namespace nts {
    class GenericGate: virtual public ILogicGate
    {
        public:
            GenericGate(const std::string &name);
            ~GenericGate() = default;
            nts::Tristate getInput1();
            nts::Tristate getInput2();
            nts::Tristate getOutput();
            std::string getName();
            void setInput1(nts::Tristate);
            void setInput2(nts::Tristate);
            void setOutput(nts::Tristate);
            int findPinIndex(size_t pin) const override;
            void setLink(std::size_t pin, nts::ILogicGate &other, std::size_t otherPin) override;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
            void dump();
            void setPin(size_t pin, nts::Tristate state) override;
            pin_t &outputPin();
    protected:
            std::vector<nts::pin_t> pins;
            std::string _name;
    };
};


#endif //B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_GENGATE_HPP
