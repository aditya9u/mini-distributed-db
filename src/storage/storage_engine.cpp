#include "storage/storage_engine.hpp"

#include<iostream>

    void StorageEngine::set(const std::string& key, const std::string& value){
      data_[key]=value;
    }

    std::string StorageEngine::get(const std::string& key){
        return data_[key];
    }

    bool StorageEngine::remove(const std::string& key){
      return data_.erase(key) >0;
    }

    bool StorageEngine::exists(const std::string& key){
      return data_.find(key) != data_.end();
    }




