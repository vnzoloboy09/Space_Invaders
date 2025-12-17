#include "PlayState.h"
#include "MainMenuState.h"
#include "StateManager.h"
#include "../ui/Button.h"

PlayState::PlayState(StateManager* sm, TextureManager* texManager)
    : State(sm, texManager) 
{
	m_buttons.emplace_back(std::make_unique<Button>(
		10, 10, 100, 40, "back_button",
		[this]() { m_stateManager->queueStateChange<MainMenuState>(m_stateManager, m_texManager); }
	));
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

	for (auto& button : m_buttons)
	{
		button->update(mx, my, mousePressed);
	}
}

void PlayState::render(Renderer* renderer)
{
	for (auto& button : m_buttons)
	{
		button->render(renderer, m_texManager);
	}
}