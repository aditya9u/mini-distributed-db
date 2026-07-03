#include "command/command_registry.hpp"
#include <iostream>

CommandRegistry::CommandRegistry(StorageEngine& storage):
storage_(storage)
{
  
    registerSet();
    registerGet();
    registerRemove();
    registerExists();
    
}

bool CommandRegistry::execute(const std::vector<std::string>& tokens ){

      if (tokens.empty())
        {
            return false;
        }
  
        auto it = command_registry_.find(tokens[0]);

        if(it == command_registry_.end()){
          return false;
        }

        it->second(tokens);

        return true;

}

void CommandRegistry::registerSet(){

  command_registry_["SET"] = [this](const std::vector<std::string>& tokens)
    {
        if (tokens.size() != 3)
        {
            std::cout << "Usage: SET <key> <value>" << std::endl;
            return;
        }

        storage_.set(tokens[1], tokens[2]);
    };

}
void CommandRegistry::registerGet(){
  command_registry_["GET"] = [this](const std::vector<std::string>& tokens)
    {
        if (tokens.size() != 2)
        {
            std::cout << "Usage: GET <key>" << std::endl;
            return;
        }

        std::cout << storage_.get(tokens[1]) << std::endl;
    };
}
void CommandRegistry::registerRemove(){

  command_registry_["REMOVE"] = [this](const std::vector<std::string>& tokens)
    {
        if (tokens.size() != 2)
        {
            std::cout << "Usage: REMOVE <key>" << std::endl;
            return;
        }

        std::cout << storage_.remove(tokens[1]) << std::endl;
    };

}
void CommandRegistry::registerExists(){
  command_registry_["EXISTS"] = [this](const std::vector<std::string>& tokens)
      {
          if (tokens.size() != 2)
          {
              std::cout << "Usage: EXISTS <key>" << std::endl;
              return;
          }

          std::cout << storage_.exists(tokens[1]) << std::endl;
      };
}