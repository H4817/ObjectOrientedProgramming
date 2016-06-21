#pragma once
#include "ShapeViewer.h"

class CLineSegmentView : public CShapeViewer
{
public:
    CLineSegmentView(const sf::Vector2f & firstPoint, const sf::Vector2f & secondPoint, const Color & color);

    void draw(sf::RenderTarget & target, sf::RenderStates states) const override;

private:
    sf::VertexArray m_lineSegment;
};
