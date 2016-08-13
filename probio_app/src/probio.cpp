#include <iostream>

#include "game_model.hpp"
#include "simple_render.hpp"
#include "map_loader.hpp"
#include "collision_processor.hpp"

using namespace std;

const sf::Vector2f game_object_size(10.f, 10.f);

int main()
{
    GameMap level0;
    MapLoader loader;
    loader.load("level0.map", level0);

    float scale = 0.250f;
    float orient = -1.f;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1024, 768), "Biosphere", sf::Style::Default, settings);
    SimpleRender render(game_object_size);

    GameWorld world;

    for (size_t y = 0; y < level0.height(); ++y)
    {
        for (size_t x = 0; x < level0.width(); ++x)
        {
            if (level0.at(x, y) == 1)
            {
                std::shared_ptr<GameObject> game_object(new StaticGameObject());
                game_object->m_position = sf::Vector2f(x, y);
                world.add(game_object);
            }
        }
    }

    std::shared_ptr<GameObject> character(new Character());
    character->m_position = sf::Vector2f(5, 5);
    world.add(character);

    CollisionProcessor collision_processor;

    sf::Event event;
    sf::Clock clock;
    while (true)
    {
        window.pollEvent(event);
        if (event.type == sf::Event::Closed)
        {
            window.close();
            break;
        }

        sf::Vector2f viewSize = static_cast<sf::Vector2f>(window.getSize());
        viewSize.y *= orient;
        sf::View view(sf::Vector2f(character->m_position.x * game_object_size.x, character->m_position.y * game_object_size.y), viewSize);
        view.zoom(scale);
        window.setView(view);

        sf::Time time = clock.restart();
        window.clear(sf::Color::Black);
        const std::vector<pGameObject>& game_objects = world.getGameObjects();
        for (auto game_object : game_objects)
        {
            collision_processor.process(level0, game_object);
            game_object->update(time.asSeconds());
            render.draw(window, game_object);
        }

        window.display();
    }

    return 0;
}