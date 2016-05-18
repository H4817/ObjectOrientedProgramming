#pragma once

#include "Shape.h"

class CPoint : public IShape
{
public:
    CPoint(std::pair<int, int> coordinates);

    double GetPerimeter() const override;

    double GetArea() const override;

    std::string ToString() const override;

private:
    std::pair<int, int> m_coordinates;
};


