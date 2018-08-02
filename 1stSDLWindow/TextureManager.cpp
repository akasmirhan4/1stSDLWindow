#include "TextureManager.h"

SDL_Texture * TextureManager::LoadTexture(const char * filename)
{
	SDL_Surface* tempSurface = IMG_Load(filename);
	if (tempSurface){
		std::cout << filename << " found!" << std::endl;
		SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
		SDL_FreeSurface(tempSurface);
		return texture;
	}
	else {
		std::cout << filename << " NOT found!" << std::endl;
		return nullptr;
	}



}
