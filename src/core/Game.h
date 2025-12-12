#pragma once

#include <SDL.h>

#include "State/StateManager.h"

class Game
{
public:
	Game();
	~Game();

	void run();

private:
	bool m_isRunning;
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;

	StateManager m_stateManager;
	
	void handleEvent();
	void update(float dt);
	void render();
};

