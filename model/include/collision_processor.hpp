#pragma once

#include "game_object.hpp"
#include "tile_terrain.hpp"

#include <map>

class CollisionProcessor
{
public:
    CollisionProcessor(void);
    virtual ~CollisionProcessor(void);

    void process(const TileTerrain& terrain, pGameObject game_object);

private:
    void handleHorizontalCollision(const TileTerrain& terrain, pGameObject game_object);

    void handleVerticalCollision(const TileTerrain& terrain, pGameObject game_object);

    std::multimap<std::string, std::string> m_collision_tag_map;
};