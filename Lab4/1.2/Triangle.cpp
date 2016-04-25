#include <cmath>
#include <tuple>
#include "Triangle.h"

Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3) : m_firstPoint(x1, y1), m_secondPoint(x2, y2),
                                                                     m_thirdPoint(x3, y3)
{
    SetPerimeter();
    SetArea();
}

void Triangle::SetPerimeter()
{
    m_perimeter = m_lengthOfSides.first + m_lengthOfSides.second + m_lengthOfSides.third;
}

void Triangle::SetArea()
{
}

double Triangle::GetPerimeter()
{
    return m_perimeter;
}

double Triangle::GetArea()
{
    return m_area;
}

void Triangle::SetLengthOfSides()
{
    m_lengthOfSides = std::make_tuple(std::sqrt(
                                              pow((m_secondPoint.first - m_firstPoint.first), 2) +
                                              pow((m_secondPoint.second - m_firstPoint.second), 2)),
                                      std::sqrt(pow((m_thirdPoint.first - m_secondPoint.first), 2) +
                                                pow((m_thirdPoint.second - m_secondPoint.second), 2)), std::sqrt(
                    pow((m_firstPoint.first - m_thirdPoint.first), 2) +
                    pow((m_firstPoint.second - m_thirdPoint.second), 2)));
}

std::tuple<double, double, double> Triangle::GetLengthOfSides() const
{
    return m_lengthOfSides;
}
