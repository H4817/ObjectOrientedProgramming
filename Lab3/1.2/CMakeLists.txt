cmake_minimum_required(VERSION 3.3)
project(1_2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package (Boost COMPONENTS unit_test_framework REQUIRED)

set(SOURCE_FILES Car.cpp main.cpp)
add_executable(1_2 ${SOURCE_FILES})