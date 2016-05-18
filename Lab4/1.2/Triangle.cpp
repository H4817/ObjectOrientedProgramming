#include "Triangle.h"

CTriangle::CTriangle(std::pair<int, int> firstPoint, std::pair<int, int> secondPoint, std::pair<int, int> thirdPoint)
        : m_firstPoint(firstPoint), m_secondPoint(secondPoint), m_thirdPoint(thirdPoint)
{
    CalculateLengthsOfSides();
    CalculatePerimeter();
    CalculateArea();
}

void CTriangle::CalculatePerimeter()
{
    m_perimeter = std::get<0>(m_lengthsOfSides) + std::get<1>(m_lengthsOfSides) + std::get<2>(m_lengthsOfSides);
}

void CTriangle::CalculateArea()
{
    m_area = std::sqrt(abs(m_perimeter / 2 * (m_perimeter / 2 - std::get<0>(m_lengthsOfSides)) *
                           (m_perimeter / 2 - std::get<1>(m_lengthsOfSides)) *
                           (m_perimeter / 2 - std::get<2>(m_lengthsOfSides))));
}

double CTriangle::GetPerimeter() const
{
    return m_perimeter;
}

double CTriangle::GetArea() const
{
    return m_area;
}

void CTriangle::CalculateLengthsOfSides()
{
    m_lengthsOfSides = std::make_tuple(std::sqrt(pow((m_secondPoint.first - m_firstPoint.first), 2) +
                                                 pow((m_secondPoint.second - m_firstPoint.second), 2)),
                                       std::sqrt(pow((m_thirdPoint.first - m_secondPoint.first), 2) +
                                                 pow((m_thirdPoint.second - m_secondPoint.second), 2)), std::sqrt(
                    pow((m_firstPoint.first - m_thirdPoint.first), 2) +
                    pow((m_firstPoint.second - m_thirdPoint.second), 2)));
}

std::tuple<double, double, double> CTriangle::GetLengthsOfSides() const
{
    return m_lengthsOfSides;
}

std::string CTriangle::ToString() const
{
    std::stringstream sStream;
    sStream << "Triangle" << " x1=" << m_firstPoint.first << " y1=" << m_firstPoint.second << " x2=" <<
    m_secondPoint.first << " y2=" << m_secondPoint.second << " x3=" << m_thirdPoint.first << " y3=" <<
    m_thirdPoint.second << " First side=" << std::get<0>(m_lengthsOfSides) << " Second side=" <<
    std::get<1>(m_lengthsOfSides) << " Third side=" << std::get<2>(m_lengthsOfSides) << " P=" << m_perimeter << " S=" <<
    m_area;
    return sStream.str();
}
