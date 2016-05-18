#include "SolidShape.h"

ISolidShape::ISolidShape()
{ }

Color ISolidShape::GetLineColor() const
{
    return m_lineColor;
}

Color ISolidShape::GetBackgroundColor() const
{
    return m_backgroundColor;
}