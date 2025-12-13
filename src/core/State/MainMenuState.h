#pragma once

#include "State.h"

class Button;

class MainMenuState : public State
{
public:
	MainMenuState(StateManager* sm, TextureManager* texManager);
	~MainMenuState() override;

	void handleEvents(SDL_Event& e) override;
	void update(float dt) override;
	void render(Renderer* renderer) override;

private:
	Button* m_playButton;
	Button* m_exitButton;
};