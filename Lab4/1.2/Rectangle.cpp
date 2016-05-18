#include <sstream>
#include "Rectangle.h"

CRectangle::CRectangle(std::pair<int, int> coordinatesOfPoint, std::pair<int, int> widthAndHeight) : m_coordinatesOfPoint(
        coordinatesOfPoint), m_widthAndHeight(widthAndHeight)
{
}

double CRectangle::GetPerimeter() const
{
    return (m_widthAndHeight.first + m_widthAndHeight.second) * 2;
}

double CRectangle::GetArea() const
{
    return m_widthAndHeight.first * m_widthAndHeight.second;
}

std::string CRectangle::ToString() const
{
    std::stringstream sStream;
    sStream << "Rectangle" << " x=" << m_coordinatesOfPoint.first << " y=" << m_coordinatesOfPoint.second <<
    " width=" << m_widthAndHeight.first << " height=" << m_widthAndHeight.second << " P=" << GetPerimeter() << " S=" <<
    GetArea();
    std::string str = sStream.str();
    return str;
}