#include "resourceLoader.hpp"

#include "SDL_error.h"
#include "SDL_image.h"
#include "SDL_render.h"
#include "SDL_surface.h"
#include <string>
#include <iostream>

#include "game.hpp"

SDL_Texture *ResourceLoader::loadTexture(std::string p_filePath)
{
	SDL_Texture *newTexture = nullptr;
	SDL_Surface *loadedSurface = IMG_Load(p_filePath.c_str());

	if (loadedSurface == nullptr)
	{
		std::cerr << "Error making image surface: " << SDL_GetError() << std::endl;
		return nullptr;
	}

	newTexture = SDL_CreateTextureFromSurface(Game::gameRenderer, loadedSurface);

	if (newTexture == nullptr)
	{
		std::cerr << "Error making image texture: " << SDL_GetError() << std::endl;
		return nullptr;
	}

	SDL_FreeSurface(loadedSurface);
	return newTexture;
}
