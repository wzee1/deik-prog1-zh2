#include <iostream>
#include "header/header.h"
#include "header/header.cpp"

/*
  - Bemeneti állomány egy ismeretlen sorszámú szöveges fájl
  - Sorok rendre: név, terméknév, lejárati dátum, ár
  - Olvassuk be a termékeket, Product osztályban
  - Index és kategória szerint keresése, a keresett Product kiiratása

  Plusz pont:
  - Utolsó pont binarisként
  - Futásidejű hibák kezelése
*/

int main()
{
  srand(time(NULL));

  int FILE_LENGTH = 4;

  std::vector<std::vector<std::string>> file_content = read_file("input.txt", ',');

  std::vector<Product> products;

  for (const auto &line : file_content)
  {
    std::string currentName = line[0];
    std::string currentProductName = line[1];
    std::string currentExpiryDate = line[2];
    double currentPrice = std::stod(line[3]);

    Product currentProduct = Product(
        currentName, currentProductName, currentExpiryDate, currentPrice);

    products.push_back(currentProduct);
  }

  std::string queryName;
  std::cout << "Input name who ordered (case-sensitive): ";
  std::cin >> queryName;

  std::ofstream output;
  output.open("products.txt", std::ios::out);

  int index = -1;
  for (int i = 0; i < FILE_LENGTH; i++)
  {
    if (queryName == products[i].getName())
    {
      products[i].display();
      output << products[i].getName() << '-'
             << products[i].getProductName() << '-'
             << products[i].getExpiryDate() << '-'
             << std::to_string(products[i].getPrice()) << '\n';
    }

    std::cout << '\n';
  }

  int queryIndex;
  std::cout << "\nInput product index: ";
  std::cin >> queryIndex;

  products[queryIndex].display();

  output << products[queryIndex].getName() << '-'
         << products[queryIndex].getProductName() << '-'
         << products[queryIndex].getExpiryDate() << '-'
         << std::to_string(products[queryIndex].getPrice()) << '\n';
  output.close();

  return 0;
}