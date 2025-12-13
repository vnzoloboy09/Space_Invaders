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
	std::unique_ptr<Button> m_playButton;
	std::unique_ptr<Button> m_exitButton;
};