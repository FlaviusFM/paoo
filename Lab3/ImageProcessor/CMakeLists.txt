cmake_minimum_required(VERSION 3.2)
project(ImageProcessor)

#   standard C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#   header-ele
include_directories(inc)

#   fisiere sursa
set(SOURCE_FILES 
    src/ImageBuffer.cpp 
    src/main.cpp 
    inc/ImageBuffer.hpp
)

#   executabil
add_executable(${PROJECT_NAME} ${SOURCE_FILES})