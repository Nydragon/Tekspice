/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#ifndef B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_GENGATE_HPP
#define B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_GENGATE_HPP


#include "../ILogicGate.hpp"
#include <string>

namespace nts {
    class GenericGate: virtual public ILogicGate
    {
        public:
            explicit GenericGate(const std::string &name);
            ~GenericGate() override = default;
            nts::Tristate getInput1() override;
            nts::Tristate getInput2() override;
            nts::Tristate getOutput() override;
            std::string getName();
            void setInput1(nts::Tristate) override;
            void setInput2(nts::Tristate) override;
            void setOutput(nts::Tristate) override;
            [[nodiscard]] int findPinIndex(size_t pin) const override;
            void setLink(std::size_t pin, nts::ILogicGate &other, std::size_t otherPin) override;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
            void dump() override;
            void setPin(size_t pin, nts::Tristate state) override;
            pin_t &outputPin() override;
            std::vector<nts::pin_t> getPins() override;
    protected:
            std::vector<nts::pin_t> pins;
            std::string _name;
    };
};


#endif //B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_GENGATE_HPP
