cmake_minimum_required(VERSION 3.26)
project(Final)

set(CMAKE_CXX_STANDARD 17)

add_executable(Final main.cpp
        BasicCalculator.cpp
        ScientificCalculator.cpp
        Calculator.cpp)
