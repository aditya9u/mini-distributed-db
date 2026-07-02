#include "storage/storage_engine.hpp"

#include<iostream>
#include <fstream>

    StorageEngine::StorageEngine(const std::string& database):
    databaseFile_(database)
    {
      loadFromDisk();
    }

    void StorageEngine::set(const std::string& key, const std::string& value){
      data_[key]=value;
      saveToDisk();

    }

    std::string StorageEngine::get(const std::string& key){
        return data_[key];
    }

    bool StorageEngine::remove(const std::string& key){
      auto erase = data_.erase(key);
      if (erase > 0)
        {
            saveToDisk();
            return true;
        }
      return false;
    }

    bool StorageEngine::exists(const std::string& key){
      return data_.find(key) != data_.end();
    }

    void StorageEngine::saveToDisk(){
      std::ofstream file(databaseFile_);
      std::cout << "Map size = " << data_.size() << std::endl;
      for(const auto& entry:data_){
        file << entry.first << "=" << entry.second << "\n";
      }
    }
    void StorageEngine::loadFromDisk(){
      std::ifstream file(databaseFile_);
      std::string line;

      while (std::getline(file, line))
      {
        std::cout << line << std::endl;
        size_t position = line.find("=");
        std::string key = line.substr(0,position);
        std::string value = line.substr(position+1);
        data_[key]=value;
      }
    }




