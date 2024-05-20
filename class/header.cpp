#include "header.h"

class Car
{
  // azert protected h tudja orokolni
protected:
  int horsepower;

public:
  // constructor
  Car(int horsepower = 100)
  {
    this->horsepower = horsepower;
  }

  // destructor (mivel nincs dinamikusan lefoglalt valtozo, ezert ures)
  ~Car()
  {
    // ha lenne akkor:
    // delete valtozo;
  }

  int getHorsepower() const
  {
    return this->horsepower;
  }

  void setHorsepower(int newHorsepower)
  {
    if (newHorsepower > 0)
      this->horsepower = newHorsepower;
  }
};

class Audi : public Car
{
private:
  std::string make;

public:
  // A gyerek ()-be kell a gyerek es a szulo osszes attributuma
  // Majd kettospont utan a szulo attributumai kellenek only
  Audi(std::string make, int horsepower) : Car(horsepower)
  {
    this->make = make;
    this->horsepower = horsepower;
  }

  // destructor (mivel nincs dinamikusan lefoglalt valtozo, ezert ures)
  ~Audi() = default

      std::string getMake() const
  {
    return this->make;
  }

  void setMake(std::string newMake)
  {
    this->make = newMake;
  }
};
