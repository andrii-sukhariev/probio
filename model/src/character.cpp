#include "character.hpp"

Character::~Character()
{

}

void Character::moveLeft(void)
{
    m_velocity.x = -50.f;
}

void Character::moveRight(void)
{
    m_velocity.x = 50.f;
}

void Character::stop()
{
    m_velocity.x = 0.f;
}

void Character::jump()
{
    if (m_collision_info.ground_collision)
    {
        m_velocity.y = -55.f;
    }
}