#include <iostream>
#include "game_map.hpp"

GameMap::GameMap()
{

}

GameMap::~GameMap()
{

}

void GameMap::setSize(int width, int height)
{
    m_width = width;
    m_height = height;
    m_map_data.resize(width * height);
}

int& GameMap::at(int x, int y)
{
    return m_map_data[(m_height - y - 1) * m_width + x];
}

const int& GameMap::at(int x, int y) const
{
    return m_map_data[(m_height - y - 1) * m_width + x];
}

int GameMap::width() const
{
    return m_width;
}

int GameMap::height() const
{
    return m_height;
}

bool GameMap::isInside(int x, int y) const
{
    return (x >= 0 && x < m_width && y >= 0 && y < m_height);
}
