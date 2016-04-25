#pragma once

#include "Shape.h"

struct Color
{
    int RR = 0;
	int GG = 0;
	int BB = 0;
};

class ISolidShape : IShape
{
public:
	ISolidShape();
	void SetBackgroundColor(int RR, int GG, int BB);
    Color GetBackgroundColor();

private:
    Color m_backgroundColor;
};

