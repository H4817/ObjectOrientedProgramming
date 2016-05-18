#pragma once

#include "Shape.h"

class CLineSegment : public IShape
{
public:
    CLineSegment(const std::pair<int, int> & firstPoint, const std::pair<int, int> & secondPoint);

    double GetLengthOfLine();

    double GetPerimeter() const override;

    double GetArea() const override;

    std::string ToString() const override;

private:
    std::pair<int, int> m_firstPoint;
    std::pair<int, int> m_secondPoint;
    double m_length;
};

