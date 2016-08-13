#include "dynamic_game_object.hpp"

DynamicGameObject::DynamicGameObject(void)
{
}

DynamicGameObject::~DynamicGameObject(void)
{
}

void DynamicGameObject::update(float delta_time)
{
    m_velocity += (m_acceleration + params.m_gravity) * delta_time;

    if (m_collision_info.ground_collision)
    {
        m_position.y = std::ceil(m_position.y);
        m_velocity.y = 0;
    }

    m_position += m_velocity * delta_time;
}