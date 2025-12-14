#pragma once

#include <memory>
#include <vector>

#include "State.h"

class Button;

class SettingMenuState : public State
{
public:
	SettingMenuState(StateManager* sm, TextureManager* texManager);
	~SettingMenuState();
	void handleEvents(SDL_Event& e) override;
	void update(float dt) override;
	void render(Renderer* renderer) override;

private:
	std::vector<std::unique_ptr<Button>> m_buttons;
};

