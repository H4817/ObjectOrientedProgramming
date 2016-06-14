#include "LineSegment.h"
#include <cmath>
#include <sstream>

CLineSegment::CLineSegment(const std::pair<int, int> &firstPoint, const std::pair<int, int> &secondPoint, const Color & lineColor)
        : m_firstPoint(firstPoint), m_secondPoint(secondPoint), m_lineColor(lineColor)
{
    m_length = GetLengthOfLine();
}

double CLineSegment::GetLengthOfLine()
{
    return std::sqrt(
            pow((m_secondPoint.first - m_firstPoint.first), 2) + pow((m_secondPoint.second - m_firstPoint.second), 2));
}

double CLineSegment::GetPerimeter() const
{
    return m_length;
}

double CLineSegment::GetArea() const
{
    return 0;
}

std::string CLineSegment::ToString() const
{
    std::stringstream sStream;
    sStream << "LineSegment" << " x1=" << m_firstPoint.first << " y1=" << m_firstPoint.second << " x2=" <<
    m_secondPoint.first << " y2=" << m_secondPoint.second << " P=" << m_length << " S=0";
    std::string str = sStream.str();
    return str;
}
//TODO: m_length