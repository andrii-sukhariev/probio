#include "simple_render.hpp"

SimpleRender::SimpleRender(sf::Vector2f object_bounding_box) :
    m_object_bounding_box(object_bounding_box)
{

}

void SimpleRender::draw(sf::RenderWindow& window, std::shared_ptr<GameObject> game_object)
{
    sf::RectangleShape object_bounding_box(m_object_bounding_box);
    sf::Vector2f position(game_object->m_position.x * m_object_bounding_box.x, game_object->m_position.y * m_object_bounding_box.y);
    object_bounding_box.setPosition(position);
    window.draw(object_bounding_box);
}