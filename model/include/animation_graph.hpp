#pragma once

#include <map>
#include "animation.hpp"

class AnimationGraph
{
public:
    AnimationGraph()
        : m_active_idx(0)
    {
    }

    ~AnimationGraph() {}

    void update(std::string message);

    void addAnimation(std::string state, pAnimation animation);

    void addTransition(std::string from_state, std::string to_state, std::string message);

    pAnimation getActiveAnimation() { return m_animations[m_active_idx]; }

protected:
    std::map<std::string, int> m_indices;
    std::vector<pAnimation> m_animations;
    std::vector< std::map<std::string, int> > m_transitions;
    int m_active_idx;
};