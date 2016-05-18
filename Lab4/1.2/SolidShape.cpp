#include "SolidShape.h"

ISolidShape::ISolidShape()
{ }

void ISolidShape::SetBackgroundColor(int RR, int GG, int BB)
{
    m_backgroundColor.RR = RR;
    m_backgroundColor.GG = GG;
    m_backgroundColor.BB = BB;
}

Color ISolidShape::GetBackgroundColor()
{
    return m_backgroundColor;
}