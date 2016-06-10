cmake_minimum_required(VERSION 3.5)
project(2_3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

find_package (Boost COMPONENTS unit_test_framework REQUIRED)

set(SOURCE_FILES tests.cpp MyList.h)
add_executable(2_3 ${SOURCE_FILES})