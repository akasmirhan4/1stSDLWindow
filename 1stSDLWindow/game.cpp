#include "game.h"
#include "TextureManager.h"

SDL_Texture* playertex;
SDL_Rect srcR, destR;


Game::Game()
{
}

Game::~Game()
{
}

void Game::init(const char * title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}
	//initialized everything if return 0
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystems initialized!..." << std::endl;
		
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window) {
			std::cout << "Window created!..." << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); //white
			std::cout << "Renderer created!..." << std::endl;
		}

		playertex = TextureManager::LoadTexture("assets/player/player.png", renderer);
		if (playertex) {
			std::cout << "Player created!..." << std::endl;
		}
		else {
			std::cout << "Player image not found!..." << std::endl;
		}
		isRunning = true;
	}
	else {
		isRunning = false;
	}

}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}

}

void Game::update()
{
	counter++;
	destR.h = 128;
	destR.w = 128;
	destR.x = counter;
}

void Game::render()
{
	SDL_RenderClear(renderer);
	//this is where we add stuff to render
	SDL_RenderCopy(renderer, playertex, NULL, &destR);
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned!..." << std::endl;
}
