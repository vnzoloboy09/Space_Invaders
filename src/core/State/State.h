#pragma once

#include <SDL.h>

#include "../Renderer.h"
#include "../TextureManager.h"

class StateManager;

class State
{
public:
	State(StateManager* sm, TextureManager* texManager) : m_stateManager(sm), m_texManager(texManager) {}
	virtual ~State() {}

	virtual void handleEvents(SDL_Event& e) = 0;
	virtual void update(float dt) = 0;
	virtual void render(Renderer* renderer) = 0;

protected:
	StateManager* m_stateManager;
	TextureManager* m_texManager;
};

