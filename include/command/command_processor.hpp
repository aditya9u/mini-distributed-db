#ifndef COMMAND_PROCESSOR_HPP
#define COMMAND_PROCESSOR_HPP

#include <string>
#include "logger/logger.hpp"
#include "storage/storage_engine.hpp"
#include "command/command_registry.hpp"

class Commandprocessor {
  public:
      Commandprocessor(StorageEngine& storage,
                     Logger& logger);

      void run();
  private:
      StorageEngine& storage_;
      Logger& logger_;
      CommandRegistry commands_;

};

#endif