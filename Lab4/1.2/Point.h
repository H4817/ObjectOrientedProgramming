#pragma once

#include "Shape.h"

class CPoint : public IShape
{
public:
    CPoint(std::pair<int, int> coordinates, const Color & lineColor);

    double GetPerimeter() const override;

    double GetArea() const override;

    std::string ToString() const override;

    Color GetLineColor() const override;

private:
    std::pair<int, int> m_coordinates;
    Color m_lineColor;
};


