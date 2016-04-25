#pragma once

#include <iostream>

class IShape
{
public:
    IShape();
    virtual double GetPerimeter() = 0;
    virtual double GetArea() = 0;
    void GetLineColor();
    virtual std::string ToString() const = 0;
};


