#include <iostream>
#include <fstream>

#include "header/header.h"
#include "header/header.cpp"

/*
  - Product class --> kategória, szavatossági idő, ár attributumok
  - Konstruktor, destruktor, getter, setter
  - Statikus és dinamikus példányosítás, metódusok bemutatása
  - Akció metódus 5-15% között, ha a termék 2 napon belül lejár (aznapi dátumot be kell kérni hozzá)
  - Szöveges állományba kiírni

  Plusz feladatok:
  - Öröklődött class-ok (2 pont)
  - Kiiró operátor implementációját a Product osztályon belül
*/

int main()
{
  srand(time(NULL));

  Bread bread = Bread("food", 2024, 5, 30, 700.0, true);
  Milk milk = Milk("drink", 2024, 5, 21, 300.0, 2.8);

  bread.display();

  std::cout << "\nPRICE CHANGE NOW\n\n";

  int currentYear, currentMonth, currentDay;
  std::cout << "Input date:\n";
  std::cin >> currentYear >> currentMonth >> currentDay;
  std::cout << "Date: " << currentYear << '-' << currentMonth << '-' << currentDay << "\n\n";

  bread.discount(currentYear, currentMonth, currentDay);

  bread.display();

  // output:
  std::ofstream output;

  output.open("products.txt", std::ios::out);
  if (output.is_open())
  {
    output << "Bread:\n";
    output << "Category: " << bread.getCategory() << '\n';
    output << "Price: " << bread.getPrice() << '\n';
    output << "Expiry: "
           << bread.getExpiryYear() << ' '
           << bread.getExpiryMonth() << ' '
           << bread.getExpiryDay() << '\n';
    output << "Is whole? " << bread.getIsWhole() << '\n';

    output << "\nMilk:\n";
    output << "Category: " << milk.getCategory() << '\n';
    output << "Price: " << milk.getPrice() << '\n';
    output << "Expiry: "
           << milk.getExpiryYear() << ' '
           << milk.getExpiryMonth() << ' '
           << milk.getExpiryDay() << '\n';
    output << "Fat Percentage: " << milk.getFatPercentage() << '\n';
  }

  output.close();

  return 0;
}