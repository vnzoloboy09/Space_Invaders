#include "Button.h"
#include "../TextureManager.h"
#include "../Renderer.h"

Button::Button(int x, int y, int width, int height, const std::string& textureId)
	: m_rect{ x, y, width, height }, m_textureId(textureId)
{
}

Button::~Button()
{
}

void Button::update(int mouseX, int mouseY, bool isMousePressed)
{
	m_isHovered = (mouseX >= m_rect.x && mouseX <= m_rect.x + m_rect.w &&
				   mouseY >= m_rect.y && mouseY <= m_rect.y + m_rect.h);

	if (m_isHovered && isMousePressed) 
	{
		m_isClicked = true;
	} else {
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