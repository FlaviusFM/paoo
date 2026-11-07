cmake_minimum_required(VERSION 3.2)
project(BankingSystem)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#   include
include_directories(inc)

#   sursa
set(SOURCES
    src/BankRegistry.cpp
    src/BankAccount.cpp
    src/main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})