#include "character_commands.hpp"

void CommandMoveLeft::execute(std::shared_ptr<Character> character)
{
    character->moveLeft();
}

void CommandMoveRight::execute(std::shared_ptr<Character> character)
{
    character->moveRight();
}

void CommandStop::execute(std::shared_ptr<Character> character)
{
    character->stop();
}

void CommandJump::execute(std::shared_ptr<Character> character)
{
    character->jump();
}