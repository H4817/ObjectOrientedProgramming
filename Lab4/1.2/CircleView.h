#pragma once
#include "ShapeViewer.h"

class CCircleView : public CShapeViewer
{
public:
    CCircleView(const sf::Vector2f & center, const float & radius, const Color & lineColor, const Color & backgroundColor);

    void draw(sf::RenderTarget & target, sf::RenderStates states) const override;

private:
    sf::CircleShape m_circle;
};

