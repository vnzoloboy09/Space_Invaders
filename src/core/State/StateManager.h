#pragma once

#include <memory>

#include "State.h"

class StateManager
{
public:
	template<typename T, typename... Args>
	void changeState(Args&&... args) {
		m_currentState = std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T, typename... Args>
	void queueStateChange(Args&&... args) {
		m_pendingState = std::make_unique<T>(std::forward<Args>(args)...);
		m_shouldChangeState = true;
	}


	void handleEvents(SDL_Event& e);
	void update(float dt);
	void render(Renderer* renderer);

private:
	std::unique_ptr<State> m_currentState;
	std::unique_ptr<State> m_pendingState;
	bool m_shouldChangeState = false;
};

