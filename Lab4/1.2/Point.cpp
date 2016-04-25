#include "Point.h"
#include <sstream>
#include <string>


CPoint::CPoint(int x, int y) : m_coordinates(x, y)
{

}

CPoint::CPoint() : m_coordinates(0, 0)
{

}

double CPoint::GetPerimeter()
{
    return 0;
}

double CPoint::GetArea()
{
    return 0;
}

std::string CPoint::ToString() const
{
    std::stringstream sStream;
    sStream << "x=" << m_coordinates.first << " y=" << m_coordinates.second << " P=0" << " S=0";
    std::string str = sStream.str();
    return str;
}