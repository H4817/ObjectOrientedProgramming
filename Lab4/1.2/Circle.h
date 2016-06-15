#pragma once

#include "SolidShape.h"

class CCircle : public CSolidShape
{
public:
    CCircle(std::pair<int, int> center, int radius, const Color & lineColor, const Color & backgroundColor);

    double GetPerimeter() const override;

    double GetArea() const override;

    std::string ToString() const override;

private:
    std::pair<int, int> m_center;
    double m_radius;
};
