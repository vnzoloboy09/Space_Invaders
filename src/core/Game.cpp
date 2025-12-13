#include "Game.h"
#include "Config.h"

#include "State/MainMenuState.h"

Game::Game()
	: m_window(nullptr), m_renderer(nullptr), m_texManager(nullptr)
{
	// init Window
	if (!SDL_Init(SDL_INIT_EVERYTHING)) {
		SDL_Quit();
	}
	m_window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, false);

	if (m_window == NULL)
		SDL_Quit();

	// init Renderer and TextureManager
	m_renderer = new Renderer(m_window);
	m_texManager = new TextureManager(m_renderer);

	// set initial state
	m_isRunning = true;
	m_stateManager.changeState<MainMenuState>(&m_stateManager, m_texManager);
}

Game::~Game()
{
	SDL_DestroyWindow(m_window);
	m_renderer->~Renderer();
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
	m_renderer->clear();
	m_stateManager.render(m_renderer);
	m_renderer->present();
}