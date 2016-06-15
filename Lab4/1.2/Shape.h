#pragma once

#include <iostream>
#include <tuple>

struct Color
{
    Color() = default;

    Color(int r, int g, int b)
            : r(r), g(g), b(b)
    { };

    int r = 0;
    int g = 0;
    int b = 0;

    bool operator==(const Color &color)
    {
        return this->r == color.r && this->g == color.g && this->b == color.b;
    }
};

class IShape
{
public:
    virtual ~IShape() = default;

    virtual double GetPerimeter() const = 0;

    virtual double GetArea() const = 0;

    virtual std::string ToString() const = 0;

    virtual Color GetLineColor() const = 0;
};



