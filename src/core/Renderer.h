#pragma once

#include <SDL.h>

class Renderer
{
public:
	Renderer(SDL_Window* window);
	~Renderer();

	void clear();
	void present();
	void draw(SDL_Texture* texture, const SDL_Rect* srcRect, const SDL_Rect* destRect);
	void setTextureColor(SDL_Texture* texture, Uint8 r, Uint8 g, Uint8 b);
	SDL_Renderer* getSDLRenderer() const { return m_renderer; }

private:
	SDL_Renderer* m_renderer;
};

