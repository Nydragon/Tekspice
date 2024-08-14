/*
** EPITECH PROJECT, $Year
** Project
** File description:
** Description
*/

#include "Execution.hpp"
#include "NanoTekSpiceError.hpp"

int main(int argc, char *argv[]) {
  nts::validateArgs(argc, argv);

  auto cli = new Execution(argv[1]);

  cli->run();

  delete cli;

  return 0;
}
