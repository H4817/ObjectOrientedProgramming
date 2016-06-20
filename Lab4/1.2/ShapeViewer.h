#pragma once

#include "Shape.h"
#include <SFML/Graphics.hpp>

class CShapeViewer : public sf::Drawable
{
public:
    virtual ~CShapeViewer() = default;
};

sf::Color GetColor(const Color &color)
{
    return sf::Color(static_cast<sf::Uint8>(color.r), static_cast<sf::Uint8>(color.g), static_cast<sf::Uint8>(color.b));
}

