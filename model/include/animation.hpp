#pragma once

#include <vector>
#include <memory>
#include "SFML/System.hpp" 
#include "SFML/Graphics.hpp"

class Animation
{
public:
    Animation() {}

    void init(std::string name, sf::Texture texture, float frame_duration, std::vector<sf::IntRect>&& frames);
    void reset();
    void update(float delta_time);
    sf::Sprite& getSprite() { return m_sprite; }

private:
    int m_frame_idx;
    float m_frame_duration;
    float m_frame_time;
    std::string m_name;
    std::vector<sf::IntRect> m_frames;
    sf::Sprite m_sprite;
    sf::Texture m_texture;
};

typedef std::shared_ptr<Animation> pAnimation;