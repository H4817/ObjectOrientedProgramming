#pragma once

#include "SolidShape.h"

class Triangle : ISolidShape
{
public:
    Triangle(int x1, int y1, int x2, int y2, int x3, int y3);
    void SetPerimeter();
    void SetArea();
    double GetPerimeter() override;
    double GetArea() override;
    std::string ToString() const override;
    void SetLengthOfSides();
    std::tuple <double, double, double> GetLengthOfSides() const;

private:
    std::pair <int, int> m_firstPoint;
    std::pair <int, int> m_secondPoint;
    std::pair <int, int> m_thirdPoint;
    std::tuple <double, double, double> m_lengthOfSides;
    double m_perimeter;
    double m_area;
};

