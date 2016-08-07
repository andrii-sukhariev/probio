#pragma once

#include "game_object.hpp"
#include "game_map.hpp"

class CollisionProcessor
{
public:
    CollisionProcessor(void);
    virtual ~CollisionProcessor(void);

    bool process(const GameMap& game_map, pGameObject game_object);
    void process(pGameObject game_object1, pGameObject game_object2);
};