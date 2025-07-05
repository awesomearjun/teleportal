#pragma once

#include "ECS/Components.hpp"
#include "SDL_render.h"

class Game
{
public:
    void init(const char *p_title, int p_windowX, int p_windowY,
              int p_windowWidth, int p_windowHeight, unsigned int p_flags);
    void update();
    void destroy();
    static SDL_Renderer *gameRenderer;

private:
    SDL_Window *m_window;

	Manager manager;
	Entity *m_background;

	float windowWidth;
	float windowHeight;
};
