#pragma once

#include "Shape.h"

class ISolidShape : public IShape
{
public:
	ISolidShape();
	void SetBackgroundColor(int RR, int GG, int BB);
    Color GetBackgroundColor();

private:
    Color m_backgroundColor;
};

