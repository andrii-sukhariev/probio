#include "game_object.hpp"


GameObject::GameObject(void)
    : m_position(sf::Vector2f(0.f, 0.f))
    , m_velocity(sf::Vector2f(0.f, 0.f))
    , m_acceleration(sf::Vector2f(0.f, 0.f))
{
}

GameObject::~GameObject(void)
{
}