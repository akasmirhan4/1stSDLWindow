#include "SDL.h"
#include "game.h"

Game *game = nullptr;

int main(int argc, char *argv[]){

	game = new Game();

	game->init("First Engine!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
	while (game->running()) {
		game->handleEvents();
		game->update();
		game->render();
	}

	game->clean();

	SDL_Delay(5000);

	return 0;
}