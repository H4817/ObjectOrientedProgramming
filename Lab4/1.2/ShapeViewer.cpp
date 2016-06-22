#include "ShapeViewer.h"

sf::Color CShapeViewer::GetColor(const Color &color)
{
    return sf::Color(static_cast<sf::Uint8>(color.r), static_cast<sf::Uint8>(color.g), static_cast<sf::Uint8>(color.b));
}