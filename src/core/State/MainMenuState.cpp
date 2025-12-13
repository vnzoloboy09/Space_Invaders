#include "StateManager.h"
#include "MainMenuState.h"
#include "PlayState.h"
#include "../ui/Button.h"


MainMenuState::MainMenuState(StateManager* sm, TextureManager* texManager)
	: State(sm, texManager)
{
	m_playButton = new Button(300, 200, 200, 80, "play_button");
	m_exitButton = new Button(300, 300, 200, 80, "exit_button");
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

	m_playButton->update(mx, my, mousePressed);
	m_exitButton->update(mx, my, mousePressed);

	if (m_playButton->isClicked())
		m_stateManager->changeState<PlayState>(m_stateManager, m_texManager);

	if (m_exitButton->isClicked())
	{
		//m_stateManager->quitGame();
	}
}

void MainMenuState::render(Renderer* renderer)
{
	m_playButton->render(renderer, m_texManager);
	m_exitButton->render(renderer, m_texManager);
}