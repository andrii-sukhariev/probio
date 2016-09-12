#pragma once

#include "game_object.hpp"

class DynamicGameObject : public GameObject
{
public:
    DynamicGameObject(void);
    virtual ~DynamicGameObject(void);

    virtual void update(float delta_time, const GameWorldParams& params) override;
};