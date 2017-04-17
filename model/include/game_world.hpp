#pragma once

#include <vector>
#include "game_object.hpp"
#include "game_world_params.hpp"
#include "collision_processor.hpp"

class GameWorld : public std::enable_shared_from_this<GameWorld>
{
public:
    GameWorld();

    void update(float delta_time);

    void add(pGameObject game_object);

    const std::vector<pGameObject>& getGameObjects() const { return m_game_objects; }

    pGameObject getMainCharacter();

    void handleTerrainCollision(pGameObject game_object, sf::Vector2f translation);

    void setMainCharacter(pGameObject main_character);

    void setTerrain(const TileTerrain& tile_terrain);

private:
    std::vector<pGameObject> m_game_objects;

    pGameObject m_main_character;

    GameWorldParams m_params;

    CollisionProcessor m_collision_processor;

    TileTerrain m_tile_terrain;
};