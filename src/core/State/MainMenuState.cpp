#include "StateManager.h"
#include "MainMenuState.h"
#include "PlayState.h"
#include "SettingMenuState.h"
#include "../ui/Button.h"


MainMenuState::MainMenuState(StateManager* sm, TextureManager* texManager)
	: State(sm, texManager)
{
	m_buttons = createVerticleMenu(
		1200, 900,
		200, 80,
		40,
		{
			[this]() { m_stateManager->queueStateChange<PlayState>(m_stateManager, m_texManager); },
			[this]() { m_stateManager->queueStateChange<SettingMenuState>(m_stateManager, m_texManager); },
			[this]() { m_stateManager->requestQuit(); }
		},
		{
			"play_button",
			"setting_button",
			"exit_button"
		}
	);
}

std::vector<std::unique_ptr<Button>> MainMenuState::createVerticleMenu(
	int windowW, int windowH,
	int buttonW, int buttonH,
	int spacing,
	const std::vector<std::function<void()>>& callbacks,
	const std::vector<std::string>& textureIDs)
{
	std::vector<std::unique_ptr<Button>> buttons;

	int count = textureIDs.size();
	int totalHeight = count * buttonH + (count - 1) * spacing;

	int startY = windowH / 2 - totalHeight / 2;
	int x = windowW / 2 - buttonW / 2;

	for (int i = 0; i < count; i++) {
		int y = startY + i * (buttonH + spacing);

		buttons.emplace_back(std::make_unique<Button>(
			x, y, buttonW, buttonH,
			textureIDs[i],
			callbacks[i]
		));
	}

	return buttons;
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