#pragma once

#include "SolidShape.h"

class CCircle : public ISolidShape
{
public:
    CCircle(std::pair<int, int> center, int radius);

    double GetPerimeter() const override;

    double GetArea() const override;

    std::string ToString() const override;

private:
    std::pair<int, int> m_center;
    double m_radius;
};
