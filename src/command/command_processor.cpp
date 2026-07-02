#include <iostream>
#include <sstream>
#include "command/command_processor.hpp"

Commandprocessor::Commandprocessor(StorageEngine &storage, Logger &logger):
storage_(storage),
logger_(logger)
{

}

void Commandprocessor::run(){
  
    logger_.info("Command Processor Started");

    std::string command;

    while(true){
      std::cout<<"> ";
      std::getline(std::cin,command);
      
      std::istringstream iss(command);

      std::string operation;
      std::string key;
      std::string value;

      iss >> operation >> key >> value;

      if(operation=="SET"){
        storage_.set(key,value);
      }else if(operation=="GET"){
        logger_.info(storage_.get(key));
      }else if(operation=="REMOVE"){
        if (storage_.remove(key))
            logger_.info(key+" Is Removed");
        else
            logger_.info("Key not found");
      }else if(operation=="EXISTS"){
        if (storage_.exists(key))
            logger_.info("This key Exists");
        else
            logger_.info("This key does not Exists");
      }else{
        logger_.error("COMMAND NOT FOUND");
      }

    }
}
