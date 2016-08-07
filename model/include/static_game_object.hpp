#pragma once

#include "game_object.hpp"

class StaticGameObject : public GameObject
{
public:
    StaticGameObject(void);
    virtual ~StaticGameObject(void);

    virtual void update(float delta_time) override;
};

