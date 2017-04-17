#include <iostream>
#include "tile_terrain.hpp"

TileTerrain::TileTerrain()
{

}

TileTerrain::~TileTerrain()
{

}

void TileTerrain::setSize(int width, int height)
{
    m_width = width;
    m_height = height;
    m_map_data.resize(width * height);
}

void TileTerrain::setTileSize(sf::Vector2f tile_size)
{
    m_tile_size = tile_size;
}

sf::Vector2f TileTerrain::getTileSize() const
{
    return m_tile_size;
}

sf::Vector2f TileTerrain::getTilePosition(int x, int y) const
{
    return sf::Vector2f(m_tile_size.x * x, m_tile_size.y * y);
}

int& TileTerrain::at(int x, int y)
{
    return m_map_data[y * m_width + x];
}

const int& TileTerrain::at(int x, int y) const
{
    return m_map_data[y * m_width + x];
}

int TileTerrain::width() const
{
    return m_width;
}

int TileTerrain::height() const
{
    return m_height;
}

bool TileTerrain::isInside(int x, int y) const
{
    return (x >= 0 && x < m_width && y >= 0 && y < m_height);
}
