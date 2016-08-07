#pragma once

#include <vector>
#include "game_object.hpp"
#include "game_world_params.hpp"

class GameWorld
{
public:
    struct GameWorldParams
    {
        float gravity;

        GameWorldParams() :
            gravity(9.8f)
        {
        }
    } params;

    GameWorld();
    void update(float delta_time);
    void add(std::shared_ptr<GameObject> game_object);
    const std::vector<pGameObject>& getGameObjects() const { return m_game_objects; }


private:
    std::vector<pGameObject> m_game_objects;
    size_t m_cnt;
};