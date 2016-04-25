#pragma once

#include "Shape.h"

class CPoint : IShape
{
public:
    CPoint(int x, int y);
    CPoint();
    double GetPerimeter() override;
    double GetArea() override;
    std::string ToString() const override;

private:
    std::pair <int, int> m_coordinates;
};


