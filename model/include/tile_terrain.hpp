#pragma once

#include <vector>

#include "SFML/System.hpp"

class TileTerrain
{
public:
    TileTerrain();

    ~TileTerrain();

    void setSize(int width, int height);

    void setTileSize(sf::Vector2f tile_size);

    sf::Vector2f getTileSize() const;

    sf::Vector2f getTilePosition(int x, int y) const;

    int& at(int x, int y);

    const int& at(int x, int y) const;

    int width() const;

    int height() const;

    bool isInside(int x, int y) const;

private:
    std::vector<int> m_map_data;

    int m_width;

    int m_height;

    sf::Vector2f m_tile_size;
};