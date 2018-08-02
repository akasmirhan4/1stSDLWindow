#include "SDL.h"
#include "game.h"

Game *game = nullptr;

int main(int argc, char *argv[]){

	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	game = new Game();

	game->init("First Engine!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, 0);
	
	while (game->running()) {
		//start of frame
		frameStart = SDL_GetTicks();


		game->handleEvents();
		game->update();
		game->render();

		//end of frame
		frameTime = SDL_GetTicks() - frameStart;

		//cap the frame
		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}
	}

	game->clean();

	SDL_Delay(2000);

	return 0;
}