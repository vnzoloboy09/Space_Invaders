#pragma once

#include <SDL.h>

class Game
{
public:
	Game();
	~Game();

	void Run();
	void Update(float dt);
	void Draw();

private:
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;
};

