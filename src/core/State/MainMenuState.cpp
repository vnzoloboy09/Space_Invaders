#include "StateManager.h"
#include "MainMenuState.h"
#include "PlayState.h"


MainMenuState::MainMenuState(StateManager* sm)
	: State(sm)
{
}

MainMenuState::~MainMenuState()
{

}

void MainMenuState::handleEvents(SDL_Event& e)
{
	if (e.type == SDL_KEYDOWN)
	{
		if (e.key.keysym.sym == SDLK_KP_ENTER || e.key.keysym.sym == SDLK_RETURN)
		{
			m_stateManager->changeState<PlayState>(m_stateManager);
		}
	}
}

void MainMenuState::update(float dt)
{

}

void MainMenuState::render(SDL_Renderer* renderer)
{

}