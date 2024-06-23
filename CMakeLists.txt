cmake_minimum_required(VERSION 3.28)
project(RunasCpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(RunasCpp main.cpp
        parser.cpp
        parser.h)
