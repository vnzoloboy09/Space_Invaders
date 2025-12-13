#pragma once

#include "State.h"

class MainMenuState : public State
{
public:
	MainMenuState(StateManager* sm);
	~MainMenuState() override;
	void handleEvents(SDL_Event& e) override;
	void update(float dt) override;
	void render(Renderer& renderer) override;
};