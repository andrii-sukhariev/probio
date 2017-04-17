#pragma once


#include "command.hpp"

class CommandMoveLeft : public Command
{
public:
    virtual void execute(std::shared_ptr<Character> character) override;
};

class CommandMoveRight : public Command
{
public:
    virtual void execute(std::shared_ptr<Character> character) override;
};

class CommandMoveUp : public Command
{
public:
    virtual void execute(std::shared_ptr<Character> character) override;
};

class CommandMoveDown : public Command
{
public:
    virtual void execute(std::shared_ptr<Character> character) override;
};


class CommandStop : public Command
{
public:
    virtual void execute(std::shared_ptr<Character> character) override;
};