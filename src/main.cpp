#include "SDL_video.h"
#include "game.hpp"

int main()
{
	Game game;
	game.init("Teleportal", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 768, 0);
	game.update();
	game.destroy();
}
