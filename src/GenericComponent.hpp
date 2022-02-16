/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#ifndef B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_GENERICCOMPONENT_HPP
#define B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_GENERICCOMPONENT_HPP

#include <string>
#include <vector>
#include <deque>
#include <unordered_map>
#include "IComponent.hpp"
#include "ILogicGate.hpp"

namespace nts
{
    typedef struct
    {
        size_t pin = 0;
        IComponent *comp_r = nullptr;
    } componentConnection;

    typedef struct
    {
        size_t pin = 0;
        ILogicGate *gate_r = nullptr;
    } logicGateConnection;

    typedef struct
    {
        size_t number = 0;
        nts::Tristate state = nts::Tristate::UNDEFINED;
        componentConnection outer_connection = componentConnection();
        logicGateConnection inner_connection = logicGateConnection();
    } pin_t;

    class GenericComponent : public virtual IComponent
    {
        std::string _name;

        std::string _type;

        size_t _pin_no;

        std::vector<ILogicGate *> circuitry;

    public:
        std::vector<pin_t> pins;

        GenericComponent(const std::string &type, const std::string &name);

        ~GenericComponent() = default;

        void simulate(std::size_t tick);

        nts::Tristate compute(std::size_t pin) override;

        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);

        void dump() const override;

        static ILogicGate *fetchGate(const std::string &type, const std::string &name);

        int findGateIndex(const std::string &name) const;

        int findPinIndex(size_t pin) const;

        std::string getName() const;

        std::string getType() const;
    };
}

#endif //B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_GENERICCOMPONENT_HPP
