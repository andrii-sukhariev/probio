#pragma once

#include <fstream>
#include "animation.hpp"

class AnimationLoader
{
public:
    static pAnimation load(std::string file_name)
    {
        pAnimation animation = pAnimation(new Animation());

        std::ifstream fstr(file_name);
        std::string tag;

        std::string name;
        fstr >> tag >> name;

        std::string texture_file;
        fstr >> tag >> texture_file;
        sf::Texture texture;
        texture.loadFromFile(texture_file);

        float frame_duration;
        fstr >> tag >> frame_duration;

        std::vector<sf::IntRect> frames;
        while (!fstr.eof())
        {
            int x, y, w, h;
            fstr >> tag >> x >> y >> w >> h;
            frames.push_back(sf::IntRect(x, y, w, h));
        }

        animation->init(name, texture, frame_duration, std::move(frames));

        return animation;
    }
};