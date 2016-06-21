#include "TriangleView.h"

CTriangleView::CTriangleView(const sf::Vector2f &firstPoint, const sf::Vector2f &secondPoint,
                             const sf::Vector2f &thirdPoint, const Color &lineColor, const Color &backgroundColor)
{
    m_triangle.setPointCount(3);
    m_triangle.setPoint(0, firstPoint);
    m_triangle.setPoint(1, secondPoint);
    m_triangle.setPoint(2, thirdPoint);
    m_triangle.setOutlineColor(GetColor(lineColor));
    m_triangle.setFillColor(GetColor(backgroundColor));
    m_triangle.setOutlineThickness(2.f);
}

void CTriangleView::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    target.draw(m_triangle, states);
}
