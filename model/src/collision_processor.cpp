#include <iostream>
#include "collision_processor.hpp"

CollisionProcessor::CollisionProcessor(void)
{
}

CollisionProcessor::~CollisionProcessor(void)
{
}

bool CollisionProcessor::process(const GameMap& game_map, pGameObject game_object)
{
    int xr = static_cast<int>(game_object->m_position.x + 0.5f);
    int yr = static_cast<int>(game_object->m_position.y + 0.5f);

    if (yr > 0 && game_map.at(xr, yr - 1) == 1)
    {
        if (game_object->m_position.y < yr) game_object->m_position.y = yr;
        return true;
    }

    return false;
}
