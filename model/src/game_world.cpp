#include "game_world.hpp"

GameWorld::GameWorld()
{
    m_cnt = 0;
}

void GameWorld::update(float delta_time)
{
    for (pGameObject game_object : m_game_objects)
    {
        game_object->update(delta_time);
    }
}

void GameWorld::add(std::shared_ptr<GameObject> game_object)
{
    m_game_objects.push_back(game_object);
}