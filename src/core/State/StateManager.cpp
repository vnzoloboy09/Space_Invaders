#include "StateManager.h"

void StateManager::handleEvents(SDL_Event& e)
{
	if (m_currentState)
		m_currentState->handleEvents(e);
}

void StateManager::update(float dt)
{
	if(m_currentState)
		m_currentState->update(dt);

	if (m_shouldChangeState)
	{
		m_currentState = std::move(m_pendingState);
		m_shouldChangeState = false;
	}
}

void StateManager::render(Renderer* renderer)
{
	if (m_currentState)
		m_currentState->render(renderer);
}