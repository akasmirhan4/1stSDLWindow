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

void TextureManager::Draw(SDL_Texture * texture, SDL_Rect srcR, SDL_Rect destR)
{
	SDL_RenderCopy(Game::renderer, texture, &srcR, &destR);
}
