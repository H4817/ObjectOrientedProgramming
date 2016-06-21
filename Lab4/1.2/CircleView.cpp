#include "CircleView.h"

CCircleView::CCircleView(const sf::Vector2f &center, const float &radius, const Color &lineColor,
                         const Color &backgroundColor)
{
    m_circle.setPosition(center);
    m_circle.setRadius(radius);
    m_circle.setFillColor(GetColor(backgroundColor));
    m_circle.setOutlineColor(GetColor(lineColor));
    m_circle.setOutlineThickness(2.f);
}

void CCircleView::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    target.draw(m_circle, states);
}
