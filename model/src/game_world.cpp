#include "game_world.hpp"

GameWorld::GameWorld()
{
}

void GameWorld::handleTerrainCollision(pGameObject game_object, sf::Vector2f translation)
{
    m_collision_processor.process(m_tile_terrain, game_object, translation);
}

void GameWorld::update(float delta_time)
{
    for (pGameObject game_object : m_game_objects)
    {
        game_object->update(delta_time, m_params);
    }
}

void GameWorld::add(pGameObject game_object)
{
    m_game_objects.push_back(game_object);
    auto shared_world = shared_from_this();
    game_object->m_game_world = shared_from_this();
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