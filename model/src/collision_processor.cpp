#include <iostream>
#include "collision_processor.hpp"

CollisionProcessor::CollisionProcessor(void)
{
}

CollisionProcessor::~CollisionProcessor(void)
{
}

void CollisionProcessor::process(const GameMap& game_map, pGameObject game_object)
{
    game_object->m_collision_info.ground_collision = false;

    int xr = static_cast<int>(game_object->m_position.x + 0.5f);
    int yr = std::ceil(game_object->m_position.y - 1.f);

    if (!(xr >= 0 && xr < game_map.width() && yr >= 0 && yr < game_map.height())) return;

    if (game_map.at(xr, yr) == 1)
    {
        game_object->m_collision_info.ground_collision = true;
    }
}
