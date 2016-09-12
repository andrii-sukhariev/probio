#include "game_object.hpp"

GameObject::CollisionInfo::CollisionInfo()
{
    reset();
}

void GameObject::CollisionInfo::reset()
{
    ground_collision = false;
    left_wall_collision = false;
    right_wall_collision = false;
}

sf::Vector2f GameObject::ObjectBox::getTopLeft()
{
    return tl_position;
}

sf::Vector2f GameObject::ObjectBox::getBottomRight()
{
    return tl_position + size;
}

sf::Vector2f GameObject::ObjectBox::getBottomCenter()
{
    return sf::Vector2f(tl_position.x + size.x / 2, tl_position.y + size.y);
}

sf::Vector2f GameObject::ObjectBox::getCenter()
{
    return sf::Vector2f(tl_position.x + size.x / 2, tl_position.y + size.y / 2);
}

GameObject::GameObject(void)
{
}

GameObject::~GameObject(void)
{
}