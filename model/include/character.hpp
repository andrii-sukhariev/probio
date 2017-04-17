#pragma once

#include <string>
#include "dynamic_game_object.hpp"

class Character : public DynamicGameObject
{
public:
    Character(void) {}

    virtual ~Character(void) override;

    virtual void moveLeft();

    virtual void moveRight();

    virtual void moveUp();

    virtual void moveDown();


    virtual void stop();

private:
};