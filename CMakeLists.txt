cmake_minimum_required(VERSION 3.4)
project(LibThrops)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES tests/main.c)
add_executable(test1 ${SOURCE_FILES} tests/main.c)