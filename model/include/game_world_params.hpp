#pragma once

#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"

struct GameWorldParams
{
    GameWorldParams()
        : m_gravity(sf::Vector2f(0.f, 0.f))
    {
    }

    sf::Vector2f m_gravity;
};