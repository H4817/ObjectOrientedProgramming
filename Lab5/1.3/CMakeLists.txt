cmake_minimum_required(VERSION 3.3)
project(1_3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package (Boost COMPONENTS unit_test_framework REQUIRED)

set(SOURCE_FILES tests.cpp Rational.cpp Rational.h)
add_executable(1_3 ${SOURCE_FILES})