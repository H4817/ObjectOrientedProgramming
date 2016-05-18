#pragma once

#include "Shape.h"

// Remove implementation details from interface
class ISolidShape : public IShape
{
public:
	ISolidShape();
    virtual Color GetBackgroundColor()const = 0;
    virtual Color GetLineColor()const = 0;

protected:
    Color m_backgroundColor;
	Color m_lineColor;
};

