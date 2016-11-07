#include "character_input_handler.hpp"

CharacterInputHandler::CharacterInputHandler(std::shared_ptr<Character> character)
: m_character(character)
{
    bindStandardSettings();
}

CharacterInputHandler::~CharacterInputHandler()
{
}

void CharacterInputHandler::bindStandardSettings()
{
    m_button_pressed_A = std::shared_ptr<Command>(new CommandMoveLeft);
    m_button_pressed_D = std::shared_ptr<Command>(new CommandMoveRight);
    m_button_released_A = std::shared_ptr<Command>(new CommandStop);
    m_button_released_D = std::shared_ptr<Command>(new CommandStop);
    m_button_pressed_Space = std::shared_ptr<Command>(new CommandJump);
}

void CharacterInputHandler::handleInput(sf::Event event)
{
    //use map/array here
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::A)
        {
            m_character->stop();
            m_button_pressed_A->execute(m_character);
        }

        if (event.key.code == sf::Keyboard::D)
        {
            m_character->stop();
            m_button_pressed_D->execute(m_character);
        }

        if (event.key.code == sf::Keyboard::Space)
        {
            m_button_pressed_Space->execute(m_character);
        }
    }

    if (event.type == sf::Event::KeyReleased)
    {
        if (event.key.code == sf::Keyboard::A)
        {
            m_button_released_A->execute(m_character);
        }

        if (event.key.code == sf::Keyboard::D)
        {
            m_button_released_D->execute(m_character);
        }
    }
}