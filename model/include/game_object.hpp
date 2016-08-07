#pragma once

#include <memory>
#include <string>
#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"

#include "game_world_params.hpp"

class GameObject
{
public:
    GameObject(void);
    virtual ~GameObject(void);

    virtual void update(float delta_time) = 0;

    sf::Vector2f m_velocity;
    sf::Vector2f m_acceleration;
    sf::Vector2f m_position;

    std::string m_name;
    sf::Sprite m_sprite;

protected:
    GameWorldParams params;
};

typedef std::shared_ptr<GameObject> pGameObject;