#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char * textureSheet, SDL_Renderer * in_renderer, int x, int y)
{
	renderer = in_renderer;
	objTexture = TextureManager::LoadTexture(textureSheet, in_renderer);
	xpos = x;
	ypos = y;
}

GameObject::~GameObject()
{
}

void GameObject::Update()
{
	xpos++;
	ypos++;

	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w*2;
	destRect.h = srcRect.h * 2;

}

void GameObject::Render()
{
	SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}
