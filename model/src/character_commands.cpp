#include "character_commands.hpp"

void CommandMoveLeft::execute(std::shared_ptr<Character> character)
{
    character->moveLeft();
}

void CommandMoveRight::execute(std::shared_ptr<Character> character)
{
    character->moveRight();
}

void CommandMoveUp::execute(std::shared_ptr<Character> character)
{
    character->moveUp();
}

void CommandMoveDown::execute(std::shared_ptr<Character> character)
{
    character->moveDown();
}

void CommandStop::execute(std::shared_ptr<Character> character)
{
    character->stop();
}