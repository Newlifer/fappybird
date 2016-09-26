cmake_minimum_required(VERSION 3.6.2)

project(fappybird)

set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -O2 -Wall -Wextra -pedantic -std=c++14")

add_executable(fappybird "src/main.cpp")

