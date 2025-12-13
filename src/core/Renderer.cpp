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

SDL_Renderer* Renderer::getSDLRenderer() const
{
	return m_renderer;
}

void Renderer::clear()
{
	SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
	SDL_RenderClear(m_renderer);
}

void Renderer::present()
{
	SDL_RenderPresent(m_renderer);
}