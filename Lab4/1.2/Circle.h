#pragma once

#include "SolidShape.h"

class CCircle : ISolidShape
{
public:
    CCircle(int x, int y, int radius);

    void SetPerimeter();

    void SetArea();

    double GetPerimeter() override;

    double GetArea() override;

    std::string ToString() const override;

private:
    std::pair<int, int> m_center;
    double m_radius;
    double m_perimeter;
    double m_area;
};
