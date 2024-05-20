#include <iostream>
#include "header.h"

int getRandomInt(int min, int max)
{
  return rand() % (max + 1 - min) + min;
}

class Product
{
protected:
  std::string category;
  int expiryYear;
  int expiryMonth;
  int expiryDay;
  double price;

public:
  // instructor
  Product(
      std::string category,
      int expiryYear,
      int expiryMonth,
      int expiryDay,
      double price)
  {
    this->category = category;
    this->expiryYear = expiryYear;
    this->expiryMonth = expiryMonth;
    this->expiryDay = expiryDay;
    this->price = price;
  }

  // destructor
  ~Product() = default;

  // getter
  std::string getCategory() const
  {
    return this->category;
  }

  int getExpiryYear() const
  {
    return this->expiryYear;
  }

  int getExpiryMonth() const
  {
    return this->expiryMonth;
  }

  int getExpiryDay() const
  {
    return this->expiryDay;
  }

  double getPrice() const
  {
    return this->price;
  }

  // setters
  void setCategory(int newCategory)
  {
    this->category = newCategory;
  }

  void setExpiryYear(int newYear)
  {
    this->expiryYear = newYear;
  }

  void setExpiryMonth(int newMonth)
  {
    if (newMonth >= 1 && newMonth <= 12)
      this->expiryMonth = newMonth;
  }

  void setExpiryDay(int newDay)
  {
    // nem figyeli hogy milyen honap
    if (newDay >= 1 && newDay <= 31)
      this->expiryDay = newDay;
  }

  // akció
  void discount(
      int currentYear, int currentMonth, int currentDay)
  {
    int dayDifference = currentDay - this->expiryDay;
    if (dayDifference < 0)
      dayDifference *= -1;

    if (
        (currentYear == this->expiryYear) &&
        (currentMonth == this->expiryMonth) &&
        (dayDifference <= 2))
    {
      double discount = getRandomInt(5, 15) / 100.0;
      double newPrice = this->price - this->price * discount;
      this->price = newPrice;
    }
  }

  // display method
  void display()
  {
    std::cout << "Current Product Info:\n";
    std::cout << "Category: " << this->getCategory() << '\n';
    std::cout << "Price: " << this->getPrice() << '\n';
    std::cout << "Expiry: "
              << this->getExpiryYear() << ' '
              << this->getExpiryMonth() << ' '
              << this->getExpiryDay() << '\n';
  }
};

class Bread : public Product
{
private:
  bool isWhole;

public:
  // contstructor
  Bread(std::string category,
        int expiryYear,
        int expiryMonth,
        int expiryDay,
        double price,
        bool isWhole) : Product(category, expiryYear, expiryMonth, expiryDay, price)
  {
    this->category = category;
    this->expiryYear = expiryYear;
    this->expiryMonth = expiryMonth;
    this->expiryDay = expiryDay;
    this->price = price;
    this->isWhole = isWhole;
  }

  // destructor
  ~Bread() = default;

  // getter
  int getIsWhole() const
  {
    return this->isWhole;
  }

  // setter
  void setIsWhole(bool newIsWhole)
  {
    this->isWhole = newIsWhole;
  }
};

class Milk : public Product
{
private:
  double fatPercentage;

public:
  // contstructor
  Milk(std::string category,
       int expiryYear,
       int expiryMonth,
       int expiryDay,
       double price,
       double fatPercentage) : Product(category, expiryYear, expiryMonth, expiryDay, price)
  {
    this->category = category;
    this->expiryYear = expiryYear;
    this->expiryMonth = expiryMonth;
    this->expiryDay = expiryDay;
    this->price = price;
    this->fatPercentage = fatPercentage;
  }

  // destructor
  ~Milk() = default;

  // getter
  int getFatPercentage() const
  {
    return this->fatPercentage;
  }

  // setter
  void setFatPercentage(double newFatPercentage)
  {
    this->fatPercentage = newFatPercentage;
  }
};