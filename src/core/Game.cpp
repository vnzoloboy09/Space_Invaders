#include "Game.h"
#include "Config.h"

#include "State/MainMenuState.h"

Game::Game()
{
	// init Window
	if (!SDL_Init(SDL_INIT_EVERYTHING)) {
		SDL_Quit();
	}
	m_window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, false);

	if (m_window == NULL)
		SDL_Quit();

	// init Renderer
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED
		| SDL_RENDERER_PRESENTVSYNC);

	if (m_renderer == NULL)
		SDL_Quit();

	SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
	SDL_RenderSetLogicalSize(m_renderer, WINDOW_WIDTH, WINDOW_HEIGHT);

	m_isRunning = true;
	m_stateManager.changeState<MainMenuState>(&m_stateManager);
}

Game::~Game()
{
	SDL_DestroyWindow(m_window);
	SDL_DestroyRenderer(m_renderer);
	SDL_Quit();
}

void Game::run()
{
	Uint32 lastFrame = SDL_GetTicks();

    while (m_isRunning)
    {
		Uint32 currentFrame = SDL_GetTicks();
		float dt = (currentFrame - lastFrame) / 1000.0f;
		lastFrame = currentFrame;

		handleEvent();
		update(dt);
		render();
    }
}

void Game::handleEvent()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			m_isRunning = false;

		m_stateManager.handleEvents(event);
	}
}

void Game::update(float dt)
{
	m_stateManager.update(dt);
}

void Game::render()
{
	SDL_RenderClear(m_renderer);
	m_stateManager.render(m_renderer);
	SDL_RenderPresent(m_renderer);
}