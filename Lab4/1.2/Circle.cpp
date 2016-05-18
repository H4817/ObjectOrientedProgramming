#include "Circle.h"
#include <math.h>
#include <sstream>

CCircle::CCircle(std::pair<int, int> center, int radius) : m_center(center), m_radius(radius)
{
}

double CCircle::GetPerimeter() const
{
    return 2 * M_PI * m_radius;
}

double CCircle::GetArea() const
{
    return M_PI * pow(m_radius, 2);
}

std::string CCircle::ToString() const
{
    std::stringstream sStream;
    sStream << "Circle" << " x=" << m_center.first << " y=" << m_center.second << " R=" << m_radius << " P=" <<
    GetPerimeter() << " S=" << GetArea();
    std::string str = sStream.str();
    return str;
}
