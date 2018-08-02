#include "game.h"
#include "TextureManager.h"
#include "GameObject.h"

GameObject* player;
GameObject* zombie;

SDL_Renderer* Game::renderer = nullptr;

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

		player = new GameObject("assets/characters/player.png",300,50);
		zombie = new GameObject("assets/characters/zombie.png", 50, 50);

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
	player->Update();
	zombie->Update();
}

void Game::render()
{
	SDL_RenderClear(renderer);
	//this is where we add stuff to render
	player->Render();
	zombie->Render();
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned!..." << std::endl;
}
