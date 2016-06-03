cmake_minimum_required(VERSION 3.5)
project(2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
find_package (Boost COMPONENTS unit_test_framework REQUIRED)

set(SOURCE_FILES MyString.cpp MyString.h tests.cpp)
add_executable(2 ${SOURCE_FILES})