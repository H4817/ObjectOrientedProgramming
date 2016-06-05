cmake_minimum_required(VERSION 3.5)
project(3_1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package (Boost COMPONENTS unit_test_framework REQUIRED)

set(SOURCE_FILES tests.cpp IPerson.h IPupil.h ITeacher.h IStudent.h IWorker.h Pupil.h Teacher.h IAdvancedStudent.h Student.h Worker.h AdvancedStudent.h StudentImpl.h PersonImpl.h)
add_executable(3_1 ${SOURCE_FILES})