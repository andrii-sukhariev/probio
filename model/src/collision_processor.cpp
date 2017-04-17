#include <iostream>
#include "collision_processor.hpp"

CollisionProcessor::CollisionProcessor(void)
{
}

CollisionProcessor::~CollisionProcessor(void)
{
}

void CollisionProcessor::process(const TileTerrain& terrain, pGameObject game_object, sf::Vector2f translation)
{
    game_object->collision_info.reset();
    handleHorizontalCollision(terrain, game_object, translation.x);
    handleVerticalCollision(terrain, game_object, translation.y);
}

void CollisionProcessor::handleHorizontalCollision(const TileTerrain& terrain, pGameObject game_object, float dx)
{
    sf::Vector2f tl = game_object->object_box.tl_position + sf::Vector2f(dx, 0.f);
    sf::Vector2f sz = game_object->object_box.size;

    const float tile_width = terrain.getTileSize().x;
    const float tile_height = terrain.getTileSize().y;

    for (int y = tl.y / tile_height; y < (tl.y + sz.y) / tile_height; ++y)
    {
        int x = (tl.x + sz.x) / tile_width;
        if (terrain.isInside(x, y) && terrain.at(x, y) == 1 && game_object->velocity.x >= 0)
        {
            game_object->collision_info.right_wall_collision = true;
        }

        x = tl.x / tile_width;
        if (terrain.isInside(x, y) && terrain.at(x, y) == 1 && game_object->velocity.x <= 0)
        {
            game_object->collision_info.left_wall_collision = true;
        }
    }
}

void CollisionProcessor::handleVerticalCollision(const TileTerrain& terrain, pGameObject game_object, float dy)
{
    sf::Vector2f tl = game_object->object_box.tl_position + sf::Vector2f(0.f, dy);
    sf::Vector2f sz = game_object->object_box.size;

    const float tile_width = terrain.getTileSize().x;
    const float tile_height = terrain.getTileSize().y;

    for (int x = tl.x / tile_width; x < (tl.x + sz.x) / tile_width; ++x)
    {
        int y = (tl.y + sz.y) / tile_height;
        if (terrain.isInside(x, y) && terrain.at(x, y) == 1 && game_object->velocity.y >= 0)
        {
            game_object->collision_info.ground_collision = true;
        }

        y = tl.y / tile_height;
        if (terrain.isInside(x, y) && terrain.at(x, y) == 1 && game_object->velocity.y <= 0)
        {
            game_object->collision_info.ceiling_collision = true;
        }
    }
}