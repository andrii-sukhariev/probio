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
    m_position += m_velocity * delta_time;
}