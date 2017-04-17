#include "animation.hpp"

void Animation::init(std::string name, sf::Texture texture, float frame_duration, std::vector<sf::IntRect>&& frames)
{
    m_frame_idx = 0;
    m_frame_time = 0.f;
    m_frames = std::move(frames);
    m_frame_duration = frame_duration;
    m_texture = texture;
    m_sprite.setTexture(m_texture);
    m_sprite.setTextureRect(m_frames[0]);
    m_name = name;
}

void Animation::reset()
{
    m_frame_time = 0.f;
    m_frame_idx = 0;
    m_sprite.setTextureRect(m_frames[0]);
}

void Animation::update(float delta_time)
{
    m_frame_time += delta_time;
    if (m_frame_time > m_frame_duration)
    {
        m_sprite.setTextureRect(m_frames[m_frame_idx]);
        m_frame_idx = m_frame_idx == m_frames.size() - 1 ? 0 : m_frame_idx + 1;
        m_frame_time = 0.f;
    }
}