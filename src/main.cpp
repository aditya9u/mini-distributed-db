#include <iostream>
#include "logger/logger.hpp"
#include "storage/storage_engine.hpp"
#include "command/command_processor.hpp"
#include <string>


int main() {
    Logger logger;
    std::string s = "database.db";
    StorageEngine storage(s);

    logger.info("Mini Distributed Database Started!");

    Commandprocessor processor(storage,logger);

    processor.run();



    // storage.set("city","Udgir");
    // storage.set("name","Aditya");

    // logger.info(storage.get("name"));
    // logger.info(storage.get("city"));

    

    return 0;
}