#include "StateManager.h"
#include "MainMenuState.h"
#include "PlayState.h"
#include "SettingMenuState.h"
#include "../ui/Button.h"


MainMenuState::MainMenuState(StateManager* sm, TextureManager* texManager)
	: State(sm, texManager)
{
	m_buttons.emplace_back(std::make_unique<Button>(300, 200, 200, 80, "play_button",
		[this]() { m_stateManager->queueStateChange<PlayState>(m_stateManager, m_texManager); }));
	m_buttons.emplace_back(std::make_unique<Button>(300, 300, 200, 80, "setting_button",
		[this]() { m_stateManager->queueStateChange<SettingMenuState>(m_stateManager, m_texManager); }));
	m_buttons.emplace_back(std::make_unique<Button>(300, 400, 200, 80, "exit_button",
		[this]() { m_stateManager->queueStateChange<PlayState>(m_stateManager, m_texManager); }));
}

MainMenuState::~MainMenuState()
{

}

void MainMenuState::handleEvents(SDL_Event& e)
{
	
}

void MainMenuState::update(float dt)
{
	int mx, my;
	SDL_GetMouseState(&mx, &my);

	bool mousePressed = SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT);

	for (auto& button : m_buttons)
	{
		button->update(mx, my, mousePressed);
	}
}

void MainMenuState::render(Renderer* renderer)
{
	for (auto& button : m_buttons)
	{
		button->render(renderer, m_texManager);
	}
}