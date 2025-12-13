#pragma once

#include <memory>

#include "State.h"

class Button;

class PlayState : public State {
public:
    PlayState(StateManager* sm, TextureManager* texManager);
    ~PlayState();

    void handleEvents(SDL_Event& e) override;
    void update(float dt) override;
    void render(Renderer* renderer) override;

private:
	std::unique_ptr<Button> m_backButton;
};

