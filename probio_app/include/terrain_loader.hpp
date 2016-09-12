#pragma once

#include <string>
#include <fstream>

#include "tile_terrain.hpp"

class TerrainLoader
{
public:
    TerrainLoader(void) {}
    virtual ~TerrainLoader(void) {}

    bool load(const std::string& terrain_file, TileTerrain& terrain)
    {
        std::ifstream terrain_stream(terrain_file);

        if (!terrain_stream.is_open())
        {
            return false;
        }

        size_t width, height;
        unsigned char value;
        terrain_stream >> width >> height;

        float tile_size;
        terrain_stream >> tile_size;
        terrain.setTileSize(sf::Vector2f(tile_size, tile_size));

        terrain.setSize(width, height);

        for (size_t y = 0; y < height; ++y)
        {
            for (size_t x = 0; x < width; ++x)
            {
                terrain_stream >> value;
                terrain.at(x, y) = static_cast<size_t>(value) - 48;
            }
        }

        return true;
    }
};