#pragma once

#include <iostream>
#include <tuple>

struct Color
{
    int RR;
    int GG;
    int BB;
    std::tuple<int, int, int> color;
};

class IShape
{
public:
    virtual ~IShape() = default;

    virtual double GetPerimeter() const = 0;

    virtual double GetArea() const = 0;

    virtual std::string ToString() const = 0;
};


