cmake_minimum_required(VERSION 3.5)
project(2_3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package (Boost COMPONENTS unit_test_framework REQUIRED)

set(SOURCE_FILES main.cpp MyList.h)
add_executable(2_3 ${SOURCE_FILES})