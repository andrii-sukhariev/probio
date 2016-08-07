#pragma once

#include <string>
#include <fstream>

#include "game_map.hpp"

class MapLoader
{
public:
    MapLoader(void) {}
    virtual ~MapLoader(void) {}

    void load(const std::string& map_file, GameMap& map)
    {
        std::ifstream map_stream(map_file);

        size_t width, height;
        unsigned char value;
        map_stream >> width >> height;

        map.setSize(width, height);

        for (size_t y = 0; y < height; ++y)
        {
            for (size_t x = 0; x < width; ++x)
            {
                map_stream >> value;
                map.at(x, y) = static_cast<size_t>(value) - 48;
            }
        }
    }
};