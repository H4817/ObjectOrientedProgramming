#pragma once

#include "ShapeViewer.h"

class CRectangleView : public CShapeViewer
{
public:
    CRectangleView(const sf::Vector2f &upLeftPoint, const sf::Vector2f &widthAndHeight, const Color &lineColor,
                   const Color &backgroundColor);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

private:
    sf::RectangleShape m_rectangle;
};

