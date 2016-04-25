#include <sstream>
#include "Rectangle.h"

Rectangle::Rectangle(int x, int y, double width, double height) : m_coordinatesOfPoint(x, y), m_width(width), m_height(height)
{
    SetPerimeter();
    SetArea();
}

void Rectangle::SetPerimeter()
{
    m_perimeter = (m_width + m_height) * 2;
}

void Rectangle::SetArea()
{
    m_area = m_width * m_height;
}

double Rectangle::GetPerimeter()
{
    return m_perimeter;
}

double Rectangle::GetArea()
{
    return m_area;
}

std::string Rectangle::ToString() const
{
    std::stringstream sStream;
    sStream << "x=" << m_coordinatesOfPoint.first << " y=" << m_coordinatesOfPoint.second << " width=" << m_width << " height=" << m_height << " P=" << m_perimeter << " S=" << m_area;
    std::string str = sStream.str();
    return str;
}