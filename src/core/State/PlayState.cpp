#include "PlayState.h"
#include "MainMenuState.h"
#include "StateManager.h"


PlayState::PlayState(StateManager* sm, TextureManager* texManager)
    : State(sm, texManager) 
{
}

PlayState::~PlayState() {}

void PlayState::handleEvents(SDL_Event& e) 
{
	if (e.type == SDL_KEYDOWN)
	{
		if (e.key.keysym.sym == SDLK_KP_ENTER || e.key.keysym.sym == SDLK_RETURN)
		{
			m_stateManager->changeState<MainMenuState>(m_stateManager, m_texManager);
		}
	}
}

void PlayState::update(float dt) 
{

}

void PlayState::render(Renderer* renderer) 
{
	SDL_SetRenderDrawColor(renderer->getSDLRenderer(), 0, 0, 255, 255);
}