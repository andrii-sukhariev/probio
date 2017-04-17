#include "character.hpp"

namespace
{
    float VELOCITY = 50.f;
}

Character::~Character()
{

}

void Character::moveLeft(void)
{
    velocity.x = -VELOCITY;
    animation_graph->update("LEFT");
}

void Character::moveRight(void)
{
    velocity.x = VELOCITY;
    animation_graph->update("RIGHT");
}

void Character::moveUp(void)
{
    velocity.y = -VELOCITY;
    animation_graph->update("UP");
}

void Character::moveDown(void)
{
    velocity.y = VELOCITY;
    animation_graph->update("DOWN");
}

void Character::stop()
{
    velocity.x = 0.f;
    velocity.y = 0.f;
}