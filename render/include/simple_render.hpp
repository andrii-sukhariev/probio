#pragma once

#include "game_model.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class SimpleRender
{
public:
    SimpleRender();
    void draw(sf::RenderWindow& window, std::shared_ptr<GameObject> game_object);
};