/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#ifndef B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_GENERICCOMPONENT_HPP
#define B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_GENERICCOMPONENT_HPP

#include "../ILogicGate.hpp"
#include "../types.hpp"
#include "ParentComponent.hpp"
#include <string>
#include <vector>

namespace nts {
class GenericComponent : public virtual ParentComponent {
  size_t _pin_no;

  std::vector<ILogicGate *> circuitry;

  std::string componentCfgLocation = "src/resources/";

public:
  GenericComponent(const std::string &type, const std::string &name);

  ~GenericComponent() override;

  void simulate(std::size_t tick) override;

  nts::Tristate compute(std::size_t pin) override;

  static ILogicGate *fetchGate(const std::string &type,
                               const std::string &name);

  int findGateIndex(const std::string &name) const;
};
} // namespace nts

#endif // B_OOP_400_BER_4_1_TEKSPICE_NICOLAS_LATTEMANN_GENERICCOMPONENT_HPP
