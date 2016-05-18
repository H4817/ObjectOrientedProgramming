#include "Point.h"
#include <sstream>
#include <string>


CPoint::CPoint(std::pair<int, int> coordinates) : m_coordinates(coordinates)
{ }

double CPoint::GetPerimeter() const
{
    return 0;
}

double CPoint::GetArea() const
{
    return 0;
}

std::string CPoint::ToString() const
{
    std::stringstream sStream;
    sStream << "Point" << " x=" << m_coordinates.first << " y=" << m_coordinates.second << " P=" << GetPerimeter() <<
    " S=" << GetArea();
    std::string str = sStream.str();
    return str;
}