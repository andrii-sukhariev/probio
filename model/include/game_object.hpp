#pragma once

#include <memory>
#include <string>
#include <set>
#include "SFML/System.hpp"
#include "animation_graph.hpp"
#include "game_world_params.hpp"

class GameWorld;

class GameObject : public std::enable_shared_from_this<GameObject>
{
public:

    GameObject(void);

    virtual ~GameObject(void);

    virtual void update(float delta_time, const GameWorldParams& params) = 0;

public:
    struct CollisionInfo
    {
        CollisionInfo();

        void reset();
        void resetAllButGround();

        bool ground_collision;
        bool ceiling_collision;
        bool left_wall_collision;
        bool right_wall_collision;

        std::string collision_tag;
        std::set<std::string> collision_mask;
    } collision_info;

    struct ObjectBox
    {
        sf::Vector2f size;
        sf::Vector2f tl_position;

        sf::Vector2f getCenter() { return tl_position + 0.5f * size; }
        sf::Vector2f getTopLeft() { return tl_position; }
        sf::Vector2f getBottomRight() { return tl_position + size; }

    } object_box;

    sf::Vector2f velocity;
    sf::Vector2f acceleration;

    std::shared_ptr<AnimationGraph> animation_graph;

    std::weak_ptr<GameWorld> game_world;
};

typedef std::shared_ptr<GameObject> pGameObject;