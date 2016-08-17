#pragma once

#include <memory>
#include "character.hpp"

class Command
{
public:
    virtual ~Command() {}
    virtual void execute(std::shared_ptr<Character> character) = 0;
};