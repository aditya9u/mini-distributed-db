#ifndef STORAGE_ENGINE_HPP
#define STORAGE_ENGINE_HPP

#include <string>
#include <unordered_map>

class StorageEngine {
public:
    void set(const std::string& key, const std::string& value);

    std::string get(const std::string& key);

    bool remove(const std::string& key);

    bool exists(const std::string& key);

private:
    std::unordered_map<std::string,std::string> data_;
};

#endif