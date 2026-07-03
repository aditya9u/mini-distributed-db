#ifndef COMMAND_REGISTRY_HPP
#define COMMAND_REGISTRY_HPP

#include "storage/storage_engine.hpp"

#include <string>
#include <unordered_map>
#include <functional>
#include <vector>

class CommandRegistry
{

    public:
        CommandRegistry(StorageEngine& storage);

        bool execute(const std::vector<std::string>& tokens);


    private:
        void registerSet();
        void registerGet();
        void registerRemove();
        void registerExists();
        StorageEngine& storage_;
        std::unordered_map<std::string, std::function<void(const std::vector<std::string>&)>> command_registry_;
  
};
#endif