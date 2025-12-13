#pragma once

#include <unordered_map>
#include <string>
#include <SDL.h>

#include "Renderer.h"

class TextureManager
{
public:
	TextureManager(Renderer& renderer);
	~TextureManager();

	bool loadTexture(const char* filePath, const char* id);
	void clearTexture(const char* id);
	void clearAllTextures();
	SDL_Texture* getTexture(const char* id);

private:
	Renderer m_renderer;
	std::unordered_map<std::string, SDL_Texture*> m_textureMap;
};

