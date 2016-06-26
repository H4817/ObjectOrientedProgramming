cmake_minimum_required(VERSION 3.5)
project(2_2)

find_package (Boost COMPONENTS unit_test_framework REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES tests.cpp StringList.h StringList.cpp)
add_executable(2_2 ${SOURCE_FILES})