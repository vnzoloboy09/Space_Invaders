#pragma once

#include <SDL.h>

class Renderer
{
public:
	Renderer(SDL_Window* window);
	~Renderer();

	void clear();
	void present();
	SDL_Renderer* getSDLRenderer() const;

private:
	SDL_Renderer* m_renderer;
};

