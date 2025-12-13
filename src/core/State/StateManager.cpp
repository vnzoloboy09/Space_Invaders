#include "StateManager.h"

void StateManager::handleEvents(SDL_Event& e)
{
	if (m_currentState)
		m_currentState->handleEvents(e);
}

void StateManager::update(float dt)
{
	if (m_currentState)
		m_currentState->update(dt);
}

void StateManager::render(Renderer& renderer)
{
	if (m_currentState)
		m_currentState->render(renderer);
}