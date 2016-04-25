#include "SolidShape.h"

ISolidShape::ISolidShape()
{ }

void ISolidShape::SetBackgroundColor(int RR, int GG, int BB)
{
    m_backgroundColor = {RR, GG, BB};
}

Color ISolidShape::GetBackgroundColor()
{
    return m_backgroundColor;
}