#pragma once

#include "Shape.h"

class LineSegment
{
public:
    LineSegment();

private:
    pair <int, int> m_firstPoint;
    pair <int, int> m_secondPoint;
    int m_length;
    int m_perimeter;
    int m_area;
};

