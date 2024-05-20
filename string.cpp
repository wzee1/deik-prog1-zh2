#include <iostream>
#include <string>

int main()
{
  // peldanyositas, ertekadas
  std::string s = "";
  s = "pelda";

  std::cout << s.length() << '\n'; // merete
  s += "khoz";                     // concat

  // masolas
  char *asd = "asd";
  char buffer[20];
  s.copy(asd, 1, 3);

  // kis es nagybetu konverziok

  std::string sub = s.substr(0, 3); // részstring

  // csere
  std::string s2 = "valami";
  s2.swap(s); // vagy:
  s2.replace(1, 2, s);

  // összehasonlítás
  int result = s.compare(s2);
  int result2 = s.compare("valami");

  s.erase(2, 2);                    // törlés
  size_t position = s.find('m', 0); // keresés

  if (position == std::string::npos)
    std::cout << "Nem talalhato!\n";
}