#include "dynamic_game_object.hpp"
#include "game_world.hpp"

DynamicGameObject::DynamicGameObject(void)
{
}

DynamicGameObject::~DynamicGameObject(void)
{
}

void DynamicGameObject::update(float delta_time, const GameWorldParams& params)
{
    sf::Vector2f acceleration = m_acceleration + static_cast<float>(!m_collision_info.ground_collision) * params.m_gravity;

    sf::Vector2f velocity = acceleration * delta_time;
    sf::Vector2f translation = (m_velocity + velocity) * delta_time;

    m_game_world.lock()->handleTerrainCollision(std::dynamic_pointer_cast<GameObject>(shared_from_this()), translation);

    if (m_collision_info.ground_collision || m_collision_info.ceiling_collision)
    {
        translation.y = 0;
    }

    if (m_collision_info.left_wall_collision || m_collision_info.right_wall_collision)
    {
        translation.x = 0;
    }

    m_velocity += velocity;
    m_object_box.tl_position += translation;
}