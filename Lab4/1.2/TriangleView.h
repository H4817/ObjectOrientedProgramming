#pragma once

#include "ShapeViewer.h"

class CTriangleView : public CShapeViewer
{
public:
    CTriangleView(const sf::Vector2f &firstPoint, const sf::Vector2f &secondPoint, const sf::Vector2f &thirdPoint,
                  const Color &lineColor, const Color &backgroundColor);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

private:
    sf::ConvexShape m_triangle;
};
