#pragma once

#include "Shape.h"
#include <SFML/Graphics.hpp>

class CShapeViewer : public sf::Drawable
{
public:
    virtual ~CShapeViewer() = default;
    sf::Color GetColor(const Color &color);
};

