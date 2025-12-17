#include <SDL.h>

#include "Button.h"
#include "../TextureManager.h"
#include "../Renderer.h"

Button::Button(int x, int y, int width, int height, const std::string& textureId, std::function<void()> onClick)
	: m_rect{ x, y, width, height }, m_textureId(textureId), m_onClick(onClick)
{
}

Button::~Button()
{

}

void Button::update(int mouseX, int mouseY, bool isMousePressed)
{
	SDL_Point mousePoint{ mouseX, mouseY };
	m_isHovered = SDL_PointInRect(&mousePoint, &m_rect);

	if (m_isHovered && isMousePressed && !m_isClicked) 
	{
		m_isClicked = true;
		if(m_onClick)
			m_onClick();
	} 
	else if (!isMousePressed){
		m_isClicked = false;
	}
}

void Button::setPosition(int x, int y)
{
	m_rect.x = x;
	m_rect.y = y;
}

void Button::render(Renderer* renderer, TextureManager* texManager)
{
	SDL_Texture* texture = texManager->getTexture(m_textureId.c_str());

	if (m_isHovered)
	{
		renderer->setTextureColor(texture, 200, 200, 200); // Lighten color on hover
	} else {
		renderer->setTextureColor(texture, 255, 255, 255); // Normal color
	}
	renderer->draw(texture, nullptr, &m_rect);
}

void Button::setSize(int width, int height)
{
	m_rect.w = width;
	m_rect.h = height;
}