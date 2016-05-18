#pragma once

#include <iostream>
#include <tuple>

struct Color
{
	Color() = default;
	Color(int r, int g, int b)
		: r(r)
		, g(g)
		, b(b)
	{};

	int r = 0;
	int g = 0;
	int b = 0;
};

class IShape
{
public:
    virtual ~IShape() = default;

    virtual double GetPerimeter() const = 0;

    virtual double GetArea() const = 0;

    virtual std::string ToString() const = 0;
};


