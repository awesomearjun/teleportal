#include "SDL_video.h"
#include "game.hpp"

int main()
{
	Game game;
	game.init("Teleportal", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
	game.update();
	game.destroy();
}
