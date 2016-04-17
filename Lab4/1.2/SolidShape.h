#pragma once

#include "Shape.h"

struct Color
{
    int RR = 0;
	int GG = 0;
	int BB = 0;
};

class ISolidShape
{
public:
	ISolidShape();
    void GetFillColor();

private:
    Color m_fillColor;
};

