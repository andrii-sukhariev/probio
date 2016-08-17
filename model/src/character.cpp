#include "character.hpp"

Character::~Character()
{

}

void Character::moveLeft(void)
{
    m_velocity.x = -5.f;
}

void Character::moveRight(void)
{
    m_velocity.x = 5.f;
}

void Character::stop()
{
    m_velocity.x = 0.f;
}