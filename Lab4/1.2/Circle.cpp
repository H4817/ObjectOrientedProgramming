#include "Circle.h"
#include <math.h>
#include <sstream>

CCircle::CCircle(int x, int y, int radius) : m_center(x, y), m_radius(radius)
{
    SetPerimeter();
    SetArea();
}

void CCircle::SetPerimeter()
{
    m_perimeter = 2 * M_PI * m_radius;
}

void CCircle::SetArea()
{
    m_area = M_PI * pow(m_radius, 2);
}

double CCircle::GetPerimeter()
{
    return m_perimeter;
}

double CCircle::GetArea()
{
    return m_area;
}

std::string CCircle::ToString() const
{
    std::stringstream sStream;
    sStream << "x=" << m_center.first << " y=" << m_center.second << " R=" << m_radius << " P=" << m_perimeter << " S=" << m_area;
    std::string str = sStream.str();
    return str;
}
