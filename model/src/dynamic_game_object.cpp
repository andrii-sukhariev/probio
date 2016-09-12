#include "dynamic_game_object.hpp"

DynamicGameObject::DynamicGameObject(void)
{
}

DynamicGameObject::~DynamicGameObject(void)
{
}

void DynamicGameObject::update(float delta_time, const GameWorldParams& params)
{
    m_velocity += (m_acceleration + params.m_gravity) * delta_time;

    if (m_collision_info.ground_collision)
    {
        m_velocity.y = 0;
    }

    if (m_collision_info.left_wall_collision || m_collision_info.right_wall_collision)
    {
        m_velocity.x = 0;
    }

    m_object_box.tl_position += m_velocity * delta_time;
}