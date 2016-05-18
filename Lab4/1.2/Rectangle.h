#pragma once

#include "SolidShape.h"

class CRectangle : public ISolidShape
{
public:
    CRectangle(std::pair<int, int> coordinatesOfPoint,
              std::pair<int, int> widthAndHeight);

    double GetPerimeter() const override;

    double GetArea() const override;

    std::string ToString() const override;

private:
    std::pair<int, int> m_coordinatesOfPoint;
    std::pair<int, int> m_size;
};
