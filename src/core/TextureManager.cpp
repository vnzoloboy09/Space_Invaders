#include "TextureManager.h"

TextureManager::TextureManager(Renderer* renderer)
	: m_renderer(renderer)
{
}

TextureManager::~TextureManager()
{
	clearAllTextures();
}

bool TextureManager::loadTexture(const char* filePath, const char* id)
{
	SDL_Surface* tempSurface = SDL_LoadBMP(filePath);
	if (tempSurface == nullptr) 
	{
		return false;
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(m_renderer->getSDLRenderer(), tempSurface);
	SDL_FreeSurface(tempSurface);
	if (texture == nullptr) 
	{
		return false;
	}

	m_textureMap[id] = texture;
	return true;
}

void TextureManager::clearTexture(const char* id)
{
	auto it = m_textureMap.find(id);
	if (it != m_textureMap.end()) 
	{
		SDL_DestroyTexture(it->second);
		m_textureMap.erase(it);
	}
}

void TextureManager::clearAllTextures()
{
	for (auto& pair : m_textureMap) 
	{
		SDL_DestroyTexture(pair.second);
	}
	m_textureMap.clear();
}

SDL_Texture* TextureManager::getTexture(const char* id)
{
	auto it = m_textureMap.find(id);
	if (it != m_textureMap.end())
	{
		return it->second;
	}
	return nullptr;
}