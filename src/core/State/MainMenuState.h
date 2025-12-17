#pragma once

#include <vector>
#include <functional>

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

	std::vector<std::unique_ptr<Button>> createVerticleMenu(
		int windowW, int windowH,
		int buttonW, int buttonH,
		int spacing,
		const std::vector<std::function<void()>>& callbacks,
		const std::vector<std::string>& textureIDs
	);

private:
	std::vector<std::unique_ptr<Button>> m_buttons;
};