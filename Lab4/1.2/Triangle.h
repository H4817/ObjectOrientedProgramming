#pragma once

#include "SolidShape.h"
#include <cmath>
#include <sstream>

class CTriangle : public ISolidShape
{
public:
    CTriangle(std::pair<int, int> firstPoint, std::pair<int, int> secondPoint, std::pair<int, int> thirdPoint);

    double GetPerimeter() const override;

    double GetArea() const override;

    std::string ToString() const override;

    void CalculateLengthsOfSides();

    std::tuple<double, double, double> GetLengthsOfSides() const;

private:
    void CalculatePerimeter();

    void CalculateArea();

    std::pair<int, int> m_firstPoint;
    std::pair<int, int> m_secondPoint;
    std::pair<int, int> m_thirdPoint;
    std::tuple<double, double, double> m_lengthsOfSides;
    double m_perimeter;
    double m_area;
};

