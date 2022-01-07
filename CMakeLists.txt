cmake_minimum_required(VERSION 3.10)

project(Integration)

set(CMAKE_CXX_STANDARD 17)
add_executable(example src/main.cpp)
target_include_directories(example PUBLIC include)