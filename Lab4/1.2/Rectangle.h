#pragma once

#include "SolidShape.h"

class Rectangle : ISolidShape
{
public:
    Rectangle(int x, int y, double width, double height);
    void SetPerimeter();
    void SetArea();
    double GetPerimeter() override;
    double GetArea() override;
    std::string ToString() const override;

private:
    std::pair <int, int> m_coordinatesOfPoint;
    double m_width;
    double m_height;
    double m_perimeter;
    double m_area;
};
