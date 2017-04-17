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
    m_button_pressed_W = std::shared_ptr<Command>(new CommandMoveUp);
    m_button_pressed_S = std::shared_ptr<Command>(new CommandMoveDown);

    m_button_released_A = std::shared_ptr<Command>(new CommandStop);
    m_button_released_D = std::shared_ptr<Command>(new CommandStop);
    m_button_released_W = std::shared_ptr<Command>(new CommandStop);
    m_button_released_S = std::shared_ptr<Command>(new CommandStop);
}

void CharacterInputHandler::handleInput(sf::Event event)
{
    //use map/array here
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::A)
        {
            //m_character->stop();
            m_button_pressed_A->execute(m_character);
        }

        if (event.key.code == sf::Keyboard::D)
        {
            //m_character->stop();
            m_button_pressed_D->execute(m_character);
        }

        if (event.key.code == sf::Keyboard::W)
        {
            //m_character->stop();
            m_button_pressed_W->execute(m_character);
        }

        if (event.key.code == sf::Keyboard::S)
        {
            //m_character->stop();
            m_button_pressed_S->execute(m_character);
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

        if (event.key.code == sf::Keyboard::W)
        {
            m_button_released_W->execute(m_character);
        }

        if (event.key.code == sf::Keyboard::S)
        {
            m_button_released_S->execute(m_character);
        }
    }
}