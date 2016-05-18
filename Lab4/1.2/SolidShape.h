#pragma once

#include "Shape.h"

// Remove implementation details from interface
class ISolidShape : public IShape
{
public:
	ISolidShape();
    virtual Color GetBackgroundColor()const;
    virtual Color GetLineColor()const;

protected:
    Color m_backgroundColor;
	Color m_lineColor;
};

