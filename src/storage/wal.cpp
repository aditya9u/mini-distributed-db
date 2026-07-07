#include "storage/wal.hpp"

#include <fstream>
#include <iostream>

WAL::WAL(const std::string& fileName)
    : fileName_(fileName)
{
}

void WAL::append(const std::string& operation)
{
    std::ofstream file(fileName_, std::ios::app);

    if (file.is_open())
    {
        file << operation << '\n';
    }
}

void WAL::replay(StorageEngine& storage){
  std::ifstream file(fileName_);

    if (!file.is_open())
    {
        return;
    }

  std::string line;

  while (std::getline(file, line))
  {
      std::cout << line << std::endl;
  }
  
}