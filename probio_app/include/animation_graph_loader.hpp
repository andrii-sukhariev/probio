#pragma once

#include <memory>
#include <fstream>
#include <string>
#include "animation_graph.hpp"
#include "animation_loader.hpp"

class AnimationGraphLoader
{
public:
    static std::shared_ptr<AnimationGraph> load(std::string file_name)
    {
        std::shared_ptr<AnimationGraph> graph(new AnimationGraph());

        std::ifstream fstr(file_name);

        std::string tag;
        int n;

        std::cout << "loading animations ...\n";

        // read animations
        fstr >> tag >> n;
        for (int i = 0; i < n; ++i)
        {
            std::string animation_name;
            std::string animation_file;
            fstr >> animation_name >> animation_file;
            std::cout << animation_file + "\n";
            graph->addAnimation(animation_name, AnimationLoader::load(animation_file));
        }

        // read transitions
        fstr >> tag >> n;
        for (int i = 0; i < n; ++i)
        {
            std::string animation_from_name;
            std::string animation_to_name;
            std::string message;

            fstr >> animation_from_name >> message >> animation_to_name;

            graph->addTransition(animation_from_name, animation_to_name, message);
        }

        return graph;
    }
};