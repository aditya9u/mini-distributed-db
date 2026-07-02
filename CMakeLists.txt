cmake_minimum_required(VERSION 3.20)

project(MiniDistributedDatabase)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(mini_db
    src/main.cpp
    src/logger/logger.cpp
    src/storage/storage_engine.cpp
    src/command/command_processor.cpp
)