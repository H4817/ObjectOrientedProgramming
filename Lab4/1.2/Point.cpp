#include "Point.h"
#include <sstream>
#include <string>


CPoint::CPoint(std::pair<int, int> coordinates, const Color & lineColor) : m_coordinates(coordinates)
{
    m_lineColor = lineColor;
}

double CPoint::GetPerimeter() const
{
    return 0;
}

double CPoint::GetArea() const
{
    return 0;
}

Color CPoint::GetLineColor() const
{
    return m_lineColor;
}

std::string CPoint::ToString() const
{
    std::stringstream sStream;
    sStream << "Point" << " x=" << m_coordinates.first << " y=" << m_coordinates.second << " P=" << GetPerimeter() <<
    " S=" << GetArea();
    std::string str = sStream.str();
    return str;
}