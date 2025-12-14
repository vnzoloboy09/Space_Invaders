#include "Renderer.h"

Renderer::Renderer(SDL_Window* window)
{
	m_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED
		| SDL_RENDERER_PRESENTVSYNC);
	if (m_renderer == NULL)
		SDL_Quit();
	SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
	SDL_RenderSetLogicalSize(m_renderer, 800, 600);
}

Renderer::~Renderer()
{
	SDL_DestroyRenderer(m_renderer);
}

void Renderer::clear()
{
	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
	SDL_RenderClear(m_renderer);
}

void Renderer::present()
{
	SDL_RenderPresent(m_renderer);
}

void Renderer::draw(SDL_Texture* texture, const SDL_Rect* srcRect, const SDL_Rect* destRect)
{
	if (!texture) {
		SDL_SetRenderDrawColor(m_renderer, 255, 0, 0, 255); // red box if no texture
		SDL_RenderFillRect(m_renderer, destRect);
		return;
	}

	SDL_RenderCopy(m_renderer, texture, srcRect, destRect);
}

void Renderer::setTextureColor(SDL_Texture* texture, Uint8 r, Uint8 g, Uint8 b)
{
	if (!texture) {
		SDL_Log("Warning: setTextureColor called with nullptr texture");
		return;
	}

	SDL_SetTextureColorMod(texture, r, g, b);
}