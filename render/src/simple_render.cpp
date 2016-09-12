#include "simple_render.hpp"

SimpleRender::SimpleRender()
{
}

void SimpleRender::draw(sf::RenderWindow& window, std::shared_ptr<GameObject> game_object)
{
    sf::RectangleShape object_bounding_box(game_object->m_object_box.size);
    object_bounding_box.setPosition(game_object->m_object_box.tl_position);
    window.draw(object_bounding_box);
}