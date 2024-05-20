#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "header.h"

class Product
{
protected:
  std::string name;
  std::string productName;
  std::string expiryDate;
  double price;

public:
  // instructor
  Product(
      std::string name,
      std::string productName,
      std::string expiryDate,
      double price)
  {
    this->name = name;
    this->productName = productName;
    this->expiryDate = expiryDate;
    this->price = price;
  }

  // destructor
  ~Product() = default;

  // getter
  std::string getName() const
  {
    return this->name;
  }

  std::string getProductName() const
  {
    return this->productName;
  }

  std::string getExpiryDate() const
  {
    return this->expiryDate;
  }

  double getPrice() const
  {
    return this->price;
  }

  // setters
  void setName(std::string newName)
  {
    this->name = newName;
  }

  void setProductName(std::string newProductName)
  {
    this->productName = newProductName;
  }

  void setExpiryDate(std::string newExpiryDate)
  {
    this->expiryDate = newExpiryDate;
  }

  void setPrice(double newPrice)
  {
    this->price = newPrice;
  }

  // display
  void display()
  {
    std::cout << "Info about the product:\n"
              << "Ordered by: " << this->getName()
              << "\nProduct name: " << this->getProductName()
              << "\nExpiry date: " << this->getExpiryDate()
              << "\nPrice: " << std::to_string(this->getPrice()) << "\n";
  }
};

std::vector<std::vector<std::string>> read_file(const std::string &filename, char delimiter)
{
  std::ifstream file(filename);
  std::vector<std::vector<std::string>> content;

  if (file.is_open())
  {
    std::string line;
    while (std::getline(file, line))
    {
      std::vector<std::string> splitted;
      std::istringstream iss(line);
      std::string word;

      while (std::getline(iss, word, delimiter))
      {
        splitted.push_back(word);
      }
      content.push_back(splitted);
    }
    file.close();
  }
  else
  {
    std::cerr << "Error opening file: " << filename << std::endl;
  }

  return content;
}