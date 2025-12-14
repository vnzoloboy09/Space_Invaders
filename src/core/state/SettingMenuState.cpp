#include "StateManager.h"
#include "SettingMenuState.h"
#include "MainMenuState.h"

#include "../ui/Button.h"

SettingMenuState::SettingMenuState(StateManager* sm, TextureManager* texManager)
	: State(sm, texManager)
{
	m_buttons.emplace_back(std::make_unique<Button>(10, 10, 100, 40, "back_button", 
		[this]() { m_stateManager->queueStateChange<MainMenuState>(m_stateManager, m_texManager); }));
}

SettingMenuState::~SettingMenuState()
{
}

void SettingMenuState::handleEvents(SDL_Event& e)
{
}

void SettingMenuState::update(float dt)
{
	int mx, my;
	SDL_GetMouseState(&mx, &my);

	bool mousePressed = SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT);

	for (auto& button : m_buttons)
	{
		button->update(mx, my, mousePressed);
	}
}

void SettingMenuState::render(Renderer* renderer)
{
	for (auto& button : m_buttons)
	{
		button->render(renderer, m_texManager);
	}
}