#include "SolidShape.h"

ISolidShape::ISolidShape()
{ }

Color ISolidShape::GetLineColor() const
{
    return m_lineColor;
}

Color ISolidShape::GetBackgroundColor() const
{
    return m_backgroundColor;
}

/*cmake_minimum_required(VERSION 3.3)
project(1_2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES tests.cpp Shape.h LineSegment.cpp LineSegment.h Point.cpp Point.h SolidShape.cpp SolidShape.h Triangle.h Triangle.cpp Rectangle.cpp Rectangle.h Circle.cpp Circle.h)
add_executable(1_2 ${SOURCE_FILES})
 */