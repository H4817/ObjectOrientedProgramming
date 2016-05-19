cmake_minimum_required(VERSION 3.3)
project(2_1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package (Boost COMPONENTS unit_test_framework REQUIRED)

set(SOURCE_FILES main.cpp StringStack.cpp StringStack.h)
add_executable(2_1 ${SOURCE_FILES})