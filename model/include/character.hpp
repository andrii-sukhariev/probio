#pragma once

#include <string>
#include "dynamic_game_object.hpp"

class Character : public DynamicGameObject
{
public:
    Character(void);
    virtual ~Character(void);

    virtual void moveLeft();
    virtual void moveRight();
    virtual void jump();

private:
};