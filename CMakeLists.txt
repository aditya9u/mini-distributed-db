cmake_minimum_required(VERSION 3.20)

project(MiniDistributedDatabase)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(mini_db
    src/main.cpp
)