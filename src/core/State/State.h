#pragma once

#include <SDL.h>

class StateManager;

class State
{
public:
	State(StateManager* sm) : m_stateManager(sm) {}
	virtual ~State() {}

	virtual void handleEvents(SDL_Event& e) = 0;
	virtual void update(float dt) = 0;
	virtual void render(SDL_Renderer* renderer) = 0;

protected:
	StateManager* m_stateManager;
};

