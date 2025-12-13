#include "PlayState.h"
#include "MainMenuState.h"
#include "StateManager.h"


PlayState::PlayState(StateManager* sm)
    : State(sm) 
{
}

PlayState::~PlayState() {}

void PlayState::handleEvents(SDL_Event& e) 
{
	if (e.type == SDL_KEYDOWN)
	{
		if (e.key.keysym.sym == SDLK_KP_ENTER || e.key.keysym.sym == SDLK_RETURN)
		{
			m_stateManager->changeState<MainMenuState>(m_stateManager);
		}
	}
}

void PlayState::update(float dt) 
{

}

void PlayState::render(Renderer& renderer) 
{
    // Draw game objects
}