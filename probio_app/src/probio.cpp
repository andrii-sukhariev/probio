#include <iostream>

#include "terrain_loader.hpp"
#include "animation_graph_loader.hpp"

#include "game_model.hpp"
#include "simple_render.hpp"
#include "collision_processor.hpp"
#include "character_input_handler.hpp"

using namespace std;

int main()
{
    const std::string resources_path = "E:/Work/Projects/probio/resources/";

    TileTerrain level0;
    TerrainLoader loader;
    if (!loader.load(resources_path + "level0.map", level0))
    {
        return 0;
    }

    //std::shared_ptr<AnimationGraph> animation_graph = AnimationGraphLoader::load(resources_path + "bomberman.graph");

    float scale = 0.5f;
    float orient = 1.f;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1024, 768), "Biosphere", sf::Style::Default, settings);
    sf::Vector2f view_size = static_cast<sf::Vector2f>(window.getSize());
    view_size.y *= orient;
    SimpleRender render;

    std::shared_ptr<GameWorld> world = std::make_shared<GameWorld>();
    world->setTerrain(level0);

    std::shared_ptr<AnimationGraph> brick_animation_graph = AnimationGraphLoader::load(resources_path + "brick.graph");
    for (size_t y = 0; y < level0.height(); ++y)
    {
        for (size_t x = 0; x < level0.width(); ++x)
        {
            if (level0.at(x, y) == 1)
            {
                std::shared_ptr<GameObject> game_object = make_shared<StaticGameObject>();
                game_object->object_box.tl_position = level0.getTilePosition(x, y);
                game_object->object_box.size = level0.getTileSize();
                game_object->animation_graph = brick_animation_graph;
                world->add(game_object);
            }
        }
    }

    std::shared_ptr<GameObject> character = std::make_shared<Character>();
    character->object_box.tl_position = level0.getTilePosition(1, 1);
    character->object_box.size = sf::Vector2f(18, 21);
    character->animation_graph = AnimationGraphLoader::load(resources_path + "bomberman.graph");
    world->setMainCharacter(character);

    CharacterInputHandler character_input_handler(std::dynamic_pointer_cast<Character>(character));

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

        sf::View view(character->object_box.getCenter(), view_size);
        view.zoom(scale);
        window.setView(view);

        character_input_handler.handleInput(event);

        sf::Time time = clock.restart();
        window.clear(sf::Color::Black);

        world->update(time.asSeconds());

        const std::vector<pGameObject>& game_objects = world->getGameObjects();
        for (auto game_object : game_objects)
        {
            render.draw(window, game_object);
        }

        window.display();
    }

    return 0;
}