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
    animation_graph->getActiveAnimation()->update(delta_time);

    sf::Vector2f acc = acceleration + static_cast<float>(!collision_info.ground_collision) * params.m_gravity;
    sf::Vector2f vel = acc * delta_time;
    sf::Vector2f translation = (velocity + vel) * delta_time;

    game_world.lock()->handleTerrainCollision(std::dynamic_pointer_cast<GameObject>(shared_from_this()), translation);

    if (collision_info.ground_collision || collision_info.ceiling_collision)
    {
        translation.y = 0;
    }

    if (collision_info.left_wall_collision || collision_info.right_wall_collision)
    {
        translation.x = 0;
    }

    velocity += vel;
    object_box.tl_position += translation;
}