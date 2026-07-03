#include <iostream>
#include <sstream>
#include "command/command_processor.hpp"
#include "command/command_registry.hpp"

Commandprocessor::Commandprocessor(StorageEngine &storage, Logger &logger):
storage_(storage),
logger_(logger),
commands_(storage)
{

}

void Commandprocessor::run(){
  
    logger_.info("Command Processor Started");

    std::string command;

    while(true){
      std::cout<<"> ";
      std::getline(std::cin,command);

      std::vector<std::string> tokens;
      
      std::istringstream iss(command);
      std::string token;

      while (iss >> token)
      {
        tokens.push_back(token);
      }

      if(!commands_.execute(tokens)){
          std::cout << "Unknown command" << std::endl;
      }

    }
}
