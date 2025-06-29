#include "game.hpp"

#include "SDL.h"
#include "SDL_error.h"
#include "SDL_events.h"
#include "SDL_render.h"
#include "SDL_video.h"
#include <iostream>

SDL_Renderer *Game::gameRenderer = nullptr;

void Game::init(const char *p_title, int p_windowX, int p_windowY,
                int p_windowWidth, int p_windowHeight, unsigned int p_flags)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        std::cerr << "Error initalizing SDL: " << SDL_GetError() << std::endl;

    m_window = SDL_CreateWindow(p_title, p_windowX, p_windowY, p_windowWidth,
                                p_windowHeight, p_flags);

    if (m_window == nullptr)
        std::cerr << "Error creating window: " << SDL_GetError() << std::endl;

    Game::gameRenderer = SDL_CreateRenderer(
        m_window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);

    if (Game::gameRenderer == nullptr)
    {
        std::cerr << "Error making gameRenderer: " << SDL_GetError()
                  << std::endl;
    }
}

void Game::update()
{
    SDL_Event event;
    bool gameRunning = true;

    while (gameRunning)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                gameRunning = false;
                break;
            }
        }

        SDL_SetRenderDrawColor(Game::gameRenderer, 255, 255, 0, 255);
        SDL_RenderClear(Game::gameRenderer);

        SDL_RenderPresent(Game::gameRenderer);
    }
}

void Game::destroy()
{
    SDL_DestroyRenderer(Game::gameRenderer);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}
