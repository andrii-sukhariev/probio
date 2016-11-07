#pragma once

#include <memory>
#include <string>
#include "SFML/System.hpp"

#include "game_world_params.hpp"

class GameWorld;

class GameObject : public std::enable_shared_from_this<GameObject>
{
public:

    GameObject(void);
    virtual ~GameObject(void);

    virtual void update(float delta_time, const GameWorldParams& params) = 0;

    //virtual std::shared_ptr<GameObject> clone() = 0;

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
    } m_collision_info;

    struct ObjectBox
    {
        sf::Vector2f getTopLeft();
        sf::Vector2f getBottomRight();
        sf::Vector2f getBottomCenter();
        sf::Vector2f getCenter();

        sf::Vector2f size;
        sf::Vector2f tl_position;
    } m_object_box;

    sf::Sprite m_sprite;
    sf::Vector2f m_velocity;
    sf::Vector2f m_acceleration;

    std::weak_ptr<GameWorld> m_game_world;
};

typedef std::shared_ptr<GameObject> pGameObject;