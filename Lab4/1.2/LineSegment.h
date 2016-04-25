#pragma once

#include "Shape.h"

class LineSegment : IShape
{
public:
    LineSegment(int x1, int y1, int x2, int y2);
    double GetLengthOfLine();
    double GetPerimeter() override;
    double GetArea() override;
    std::string ToString() const override;

private:
    std::pair <int, int> m_firstPoint;
    std::pair <int, int> m_secondPoint;
    double m_length;
};

