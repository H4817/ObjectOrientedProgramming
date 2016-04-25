#include "LineSegment.h"
#include <cmath>
#include <sstream>

LineSegment::LineSegment(int x1, int y1, int x2, int y2) : m_firstPoint(x1, y1), m_secondPoint(x2, y2)
{
    m_length = GetLengthOfLine();
}

double LineSegment::GetLengthOfLine()
{
    return std::sqrt(pow((m_secondPoint.first - m_firstPoint.first), 2) + pow((m_secondPoint.second - m_firstPoint.second), 2));
}

double LineSegment::GetPerimeter()
{
    return m_length;
}

double LineSegment::GetArea()
{
    return 0;
}

std::string LineSegment::ToString() const
{
    std::stringstream sStream;
    sStream << "x1=" << m_firstPoint.first << " y1=" << m_firstPoint.second << " x2=" << m_secondPoint.first << " y2=" << m_secondPoint.second  << " P=" << m_length << " S=0";
    std::string str = sStream.str();
    return str;
}
