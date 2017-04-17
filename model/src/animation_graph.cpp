#include "animation_graph.hpp"
#include <iostream>

void AnimationGraph::update(std::string message)
{
    m_active_idx = m_transitions[m_active_idx].at(message);
}

void AnimationGraph::addAnimation(std::string state, pAnimation animation)
{
    m_indices.insert(std::pair<std::string, int>(state, m_animations.size()));
    
    m_animations.push_back(animation);
    m_transitions.push_back(std::map<std::string, int>());
}

void AnimationGraph::addTransition(std::string from_state, std::string to_state, std::string message)
{
    int from_idx = m_indices.at(from_state);
    int to_idx = m_indices.at(to_state);
    m_transitions[m_indices.at(from_state)].insert(std::pair<std::string, int>(message, m_indices.at(to_state)));
}