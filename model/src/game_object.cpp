#include "game_object.hpp"
#include "game_world.hpp"

GameObject::CollisionInfo::CollisionInfo()
{
    reset();
}

void GameObject::CollisionInfo::reset()
{
    ground_collision = false;
    ceiling_collision = false;
    left_wall_collision = false;
    right_wall_collision = false;
}

GameObject::GameObject(void)
{
}

GameObject::~GameObject(void)
{
}