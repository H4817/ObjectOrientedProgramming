#pragma once

#include "SolidShape.h"

class CRectangle : public CSolidShape
{
public:
    CRectangle(std::pair<int, int> coordinatesOfPoint,
              std::pair<int, int> widthAndHeight, const Color & lineColor, const Color & backgroundColor);

    double GetPerimeter() const override;

    double GetArea() const override;

    std::string ToString() const override;

private:
    std::pair<int, int> m_coordinatesOfPoint;
    std::pair<int, int> m_size;
};
