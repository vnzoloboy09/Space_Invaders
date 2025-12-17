#pragma once

#include <SDL.h>

#include "State/StateManager.h"
#include "TextureManager.h"
#include "Renderer.h"

class Game
{
public:
	Game();
	~Game();

	void run();

private:
	bool m_isRunning;
	SDL_Window* m_window;
	Renderer* m_renderer;
	TextureManager* m_texManager;

	StateManager m_stateManager;
	
	void handleEvent();
	void update(float dt);
	void render();
};

