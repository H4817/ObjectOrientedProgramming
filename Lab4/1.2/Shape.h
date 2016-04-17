#pragma once

#include <iostream>

using namespace std;

class IShape
{
public:
    IShape();
    virtual void GetPerimeter() = 0;
    virtual void GetArea() = 0;
    void GetLineColor();
    virtual string ToString() const = 0;
};


