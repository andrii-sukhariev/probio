#include "game_world.hpp"

GameWorld::GameWorld()
{
}

void GameWorld::update(float delta_time)
{
    m_collision_processor.process(m_tile_terrain, m_main_character);
    for (pGameObject game_object : m_game_objects)
    {
        game_object->update(delta_time, m_params);
    }
}

void GameWorld::add(pGameObject game_object)
{
    m_game_objects.push_back(game_object);
}

pGameObject GameWorld::getMainCharacter()
{
    return m_main_character;
}

void GameWorld::setMainCharacter(pGameObject main_character)
{
    if (!m_main_character)
    {
        m_main_character = main_character;
        add(main_character);
    }
}

void GameWorld::setTerrain(const TileTerrain& tile_terrain)
{
    m_tile_terrain = tile_terrain;
}