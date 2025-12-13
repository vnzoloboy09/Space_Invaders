#pragma once

#include <SDL.h>
#include <string>

class Button
{
public:
	Button(int x, int y, int width, int height, const std::string& textureId);
	~Button();

	void update(int mouseX, int mouseY, bool isMousePressed);
	void setPosition(int x, int y);
	void setSize(int width, int height);
	void render(class Renderer* renderer, class TextureManager* texManager);
	bool isClicked() const { return m_isClicked; }

private:
	SDL_Rect m_rect;
	std::string m_textureId;

	bool m_isHovered = false;
	bool m_isClicked = false;
};