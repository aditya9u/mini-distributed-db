#pragma once

#include <string>

class StorageEngine;
class WAL
{
public:
    explicit WAL(const std::string& fileName);

    void append(const std::string& operation);

    void replay(StorageEngine& storage);

private:
    std::string fileName_;
};