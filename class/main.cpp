#include <iostream>
#include "header.h"
#include "header.cpp"

int main(int argc, char *argv[])
{
  Car unknownCar = Car();
  Audi r8 = Audi("Audi", 800);

  std::cout << unknownCar.getHorsepower() << '\n';
  std::cout << r8.getHorsepower() << '\n';
  std::cout << r8.getMake() << '\n';

  return 0;
}