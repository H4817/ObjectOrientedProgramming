#pragma once

#include "Shape.h"

class ISolidShape : public IShape
{
public:
    virtual ~ISolidShape() = default;

    virtual Color GetBackgroundColor() const = 0;
};

class CSolidShape : public ISolidShape
{
public:
    Color GetBackgroundColor() const override;

    Color GetLineColor() const override;

protected:
    Color m_backgroundColor;
    Color m_lineColor;
};

