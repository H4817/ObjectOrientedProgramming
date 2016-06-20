#include "RectangleView.h"

CRectangleView::CRectangleView(const sf::Vector2f &upLeftPoint, const sf::Vector2f &widthAndHeight,
                               const Color &lineColor, const Color &backgroundColor)
{
    m_rectangle.setPosition(upLeftPoint);
    m_rectangle.setSize(widthAndHeight);
    m_rectangle.setFillColor(GetColor(backgroundColor));
    m_rectangle.setOutlineColor(GetColor(lineColor));
    m_rectangle.setOutlineThickness(2.f);
}

void CRectangleView::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(m_rectangle, states);
}