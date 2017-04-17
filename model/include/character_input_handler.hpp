#pragma once

#include <map>
#include "character_commands.hpp"
#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"

class CharacterInputHandler
{
public:
    CharacterInputHandler(std::shared_ptr<Character> character);

    ~CharacterInputHandler();

    void handleInput(sf::Event event);

private:
    void bindStandardSettings();

    std::shared_ptr<Command> m_button_pressed_A;
    std::shared_ptr<Command> m_button_pressed_D;
    std::shared_ptr<Command> m_button_pressed_W;
    std::shared_ptr<Command> m_button_pressed_S;

    std::shared_ptr<Command> m_button_released_A;
    std::shared_ptr<Command> m_button_released_D;
    std::shared_ptr<Command> m_button_released_W;
    std::shared_ptr<Command> m_button_released_S;

    std::shared_ptr<Character> m_character;
};