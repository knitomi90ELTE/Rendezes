cmake_minimum_required(VERSION 3.3)
project(Rendezes)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Rendezes ${SOURCE_FILES})