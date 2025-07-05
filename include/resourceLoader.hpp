#pragma once

#include "SDL_render.h"
#include <string>

namespace ResourceLoader
{
SDL_Texture *loadTexture(std::string p_filePath);
};
