#ifndef STORAGE_ENGINE_HPP
#define STORAGE_ENGINE_HPP

#include <string>
#include <unordered_map>
#include "storage/wal.hpp"

class StorageEngine {
public:
    StorageEngine(const std::string& database);

    void set(const std::string& key, const std::string& value);

    std::string get(const std::string& key);

    bool remove(const std::string& key);

    bool exists(const std::string& key);

    void loadFromDisk();

    void saveToDisk();

private:
    std::unordered_map<std::string,std::string> data_;
    std::string databaseFile_;
    WAL wal_;
};

#endif