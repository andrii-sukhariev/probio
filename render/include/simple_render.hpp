#pragma once

#include "game_model.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class SimpleRender
{
public:
    SimpleRender(sf::Vector2f object_bounding_box);
    void draw(sf::RenderWindow& window, std::shared_ptr<GameObject> game_object);

private:
    sf::Vector2f m_object_bounding_box;
};