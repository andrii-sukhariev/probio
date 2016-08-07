#pragma once

#include <vector>

class GameMap
{
public:
    GameMap();
    ~GameMap();

    void setSize(int width, int height);
    int& at(int x, int y);
    const int& at(int x, int y) const;
    int width() const;
    int height() const;

private:
    std::vector<int> m_map_data;
    int m_width;
    int m_height;
};