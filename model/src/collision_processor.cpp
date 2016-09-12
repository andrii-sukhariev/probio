#include <iostream>
#include "collision_processor.hpp"

CollisionProcessor::CollisionProcessor(void)
{
}

CollisionProcessor::~CollisionProcessor(void)
{
}

void CollisionProcessor::process(const TileTerrain& terrain, pGameObject game_object)
{
    game_object->m_collision_info.reset();
    handleVerticalCollision(terrain, game_object);
    handleHorizontalCollision(terrain, game_object);
}

void CollisionProcessor::handleHorizontalCollision(const TileTerrain& terrain, pGameObject game_object)
{
    sf::Vector2f tl = game_object->m_object_box.tl_position;
    sf::Vector2f sz = game_object->m_object_box.size;

    float tile_width = terrain.getTileSize().x;
    float tile_height = terrain.getTileSize().y;

    for (int y = tl.y / tile_height; y < (tl.y + sz.y) / tile_height; ++y)
    {
        int x = (tl.x + sz.x) / tile_width;
        if (terrain.isInside(x, y) && terrain.at(x, y) == 1 && game_object->m_velocity.x >= 0)
        {
            game_object->m_object_box.tl_position.x = x * tile_width - game_object->m_object_box.size.x;
            game_object->m_collision_info.right_wall_collision = true;
        }

        x = tl.x / tile_width;
        if (terrain.isInside(x, y) && terrain.at(x, y) == 1 && game_object->m_velocity.x <= 0)
        {
            game_object->m_object_box.tl_position.x = (x + 1) * tile_width;
            game_object->m_collision_info.left_wall_collision = true;
        }
    }
}

void CollisionProcessor::handleVerticalCollision(const TileTerrain& terrain, pGameObject game_object)
{
    sf::Vector2f tl = game_object->m_object_box.tl_position;
    sf::Vector2f sz = game_object->m_object_box.size;

    float tile_width = terrain.getTileSize().x;
    float tile_height = terrain.getTileSize().y;

    for (int x = tl.x / tile_width; x < (tl.x + sz.x) / tile_width; ++x)
    {
        int y = (tl.y + sz.y) / tile_height;
        if (terrain.isInside(x, y) && terrain.at(x, y) == 1 && game_object->m_velocity.y >= 0)
        {
            game_object->m_object_box.tl_position.y = y * tile_height - game_object->m_object_box.size.y;
            game_object->m_collision_info.ground_collision = true;
        }
    }
}