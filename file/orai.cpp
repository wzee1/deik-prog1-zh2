#include <iostream>
#include <fstream>
#include <string>

class Mercedes
{
private:
  int horsepower;
  std::string make;

public:
  int getHorsepower() const
  {
    return this->horsepower;
  }

  std::string getMake() const
  {
    return this->make;
  }
};

int main()
{
  std::ifstream input;
  std::ofstream output;

  // szoveges fajl irasa
  int n = 5;
  float f = 4.35;
  std::string s = "pelda";
  bool b = true;

  output.open("pelda.txt", std::ios::out);
  if (output.is_open())
  {
    output << s;
    output << ", ";
    output << f;
    output << ", ";
    output << n << ", " << b << std::endl;
  }

  Mercedes M;
  output << M.getHorsepower();
  output << M.getMake();

  output.close();
  // olvasas
  input.open("pelda.txt", std::ios::in);
  if (input.is_open())
  {
    input >> s;
    std::string line;
    std::getline(input, line);
  }

  input.close();

  // binaris
  char buffer[256];

  output.open("pelda.bin", std::ios::out | std::ios::binary);
  output.write((char *)&n, sizeof(int));
  output.write(buffer, 256);
  output.write((char *)&M, sizeof(Mercedes));
  output.close();

  input.open("pelda.bin", std::ios::in | std::ios::binary);
  input.read((char *)&n, sizeof(int));
  input.read(buffer, 256);
  input.close();
  return 0;
}