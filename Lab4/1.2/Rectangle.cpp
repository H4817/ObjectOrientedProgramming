#include <sstream>
#include "Rectangle.h"

CRectangle::CRectangle(std::pair<int, int> coordinatesOfPoint, std::pair<int, int> widthAndHeight,
                       const Color &lineColor, const Color &backgroundColor)
        : m_coordinatesOfPoint(coordinatesOfPoint), m_size(widthAndHeight)
{
    m_lineColor = lineColor;
    m_backgroundColor = backgroundColor;
}

double CRectangle::GetPerimeter() const
{
    return (m_size.first + m_size.second) * 2;
}

double CRectangle::GetArea() const
{
    return m_size.first * m_size.second;
}

std::string CRectangle::ToString() const
{
    std::stringstream sStream;
    sStream << "Rectangle" << " x=" << m_coordinatesOfPoint.first << " y=" << m_coordinatesOfPoint.second <<
    " width=" << m_size.first << " height=" << m_size.second << " P=" << GetPerimeter() << " S=" <<
    GetArea();
    return sStream.str();
}