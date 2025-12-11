#include "Game.h"
#include "Config.h"

Game::Game()
{
	// init Window
	if (!SDL_Init(SDL_INIT_EVERYTHING)) {
		SDL_Quit();
	}
	window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, false);

	if (window == NULL)
		SDL_Quit();

	// init Renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED
		| SDL_RENDERER_PRESENTVSYNC);

	if (renderer == NULL)
		SDL_Quit();

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
	SDL_RenderSetLogicalSize(renderer, WINDOW_WIDTH, WINDOW_HEIGHT);

	isRunning = true;
}

Game::~Game() = default;

void Game::Run()
{
    SDL_Event e;

    while (isRunning)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
                isRunning = false;
        }

        SDL_Delay(16); // ~60 FPS
    }

    SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
