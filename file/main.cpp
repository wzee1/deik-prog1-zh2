#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

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

int main()
{
  std::string filename = "data.txt";
  // Ez alapján splitelünk
  char delimiter = ',';

  std::vector<std::vector<std::string>> file_content = read_file(filename, delimiter);

  // file_content.forEach(line => {...}) // JS-ben így néz ki:
  // for line in file_content: ... // Python-ban így néz ki:
  for (const auto &line : file_content)
  {
    for (const auto &word : line)
    {
      std::cout << word << ' ';
    }
    std::cout << '\n';
  }

  return 0;
}
