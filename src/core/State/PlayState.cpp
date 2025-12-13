#include "PlayState.h"
#include "MainMenuState.h"
#include "StateManager.h"
#include "../ui/Button.h"

PlayState::PlayState(StateManager* sm, TextureManager* texManager)
    : State(sm, texManager) 
{
	m_backButton = std::make_unique<Button>(10, 10, 100, 40, "back_button");
}

PlayState::~PlayState() {}

void PlayState::handleEvents(SDL_Event& e) 
{

}

void PlayState::update(float dt) 
{
	int mx, my;
	SDL_GetMouseState(&mx, &my);

	bool mousePressed = SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT);

	m_backButton->update(mx, my, mousePressed);

	if (m_backButton->isClicked())
		m_stateManager->queueStateChange<MainMenuState>(m_stateManager, m_texManager);
}

void PlayState::render(Renderer* renderer) 
{
	m_backButton->render(renderer, m_texManager);
}