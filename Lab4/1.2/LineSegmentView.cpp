#include "LineSegmentView.h"

CLineSegmentView::CLineSegmentView(const sf::Vector2f &firstPoint, const sf::Vector2f &secondPoint,
                                   const Color &color) : m_lineSegment(sf::Lines, 2)
{
    m_lineSegment[0].position = firstPoint;
    m_lineSegment[1].position = secondPoint;
    m_lineSegment[0].color = GetColor(color);
    m_lineSegment[1].color = GetColor(color);
}

void CLineSegmentView::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    target.draw(m_lineSegment, states);
}
