cmake_minimum_required(VERSION 3.15)
project(swipe)

set(CMAKE_CXX_STANDARD 14)

add_executable(swipe main.cpp pinReader.cpp pinReader.h psqReader.cpp psqReader.h phrReader.cpp phrReader.h)