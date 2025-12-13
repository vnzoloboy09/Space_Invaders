#pragma once

#include "State.h"

class PlayState : public State {
public:
    PlayState(StateManager* sm, TextureManager* texManager);
    ~PlayState();

    void handleEvents(SDL_Event& e) override;
    void update(float dt) override;
    void render(Renderer* renderer) override;
};

