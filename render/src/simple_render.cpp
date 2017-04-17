#include "simple_render.hpp"

SimpleRender::SimpleRender()
{
}

void SimpleRender::draw(sf::RenderWindow& window, std::shared_ptr<GameObject> game_object)
{
    sf::Sprite& sprite = game_object->animation_graph->getActiveAnimation()->getSprite();
    sprite.setPosition(game_object->object_box.tl_position);
    window.draw(sprite);
}