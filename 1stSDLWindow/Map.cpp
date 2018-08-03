#include "Map.h"
#include "TextureManager.h"

Map::Map()
{
	dirt = TextureManager::LoadTexture("assets/textures/dirt.png");
	grass = TextureManager::LoadTexture("assets/textures/grass.png");
	water = TextureManager::LoadTexture("assets/textures/water.png");

	int lvl1[20][25] = {
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0 },
	{ 0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0 },
	{ 0,0,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,0,0 },
	{ 0,0,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,0,0 },
	{ 0,0,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,0,0 },
	{ 0,0,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,0,0 },
	{ 0,0,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,0,0 },
	{ 0,0,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,0,0 },
	{ 0,0,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,0,0 },
	{ 0,0,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,0,0 },
	{ 0,0,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,0,0 },
	{ 0,0,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,0,0 },
	{ 0,0,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,0,0 },
	{ 0,0,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,0,0 },
	{ 0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0 },
	{ 0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
	};

	LoadMap(lvl1);
	
	srcR.x = srcR.y = 0;
	srcR.w = destR.w = 32;
	srcR.h = destR.h = 32;

	destR.x = destR.y = 0;
}


Map::~Map()
{
}

void Map::LoadMap(int arr[20][25])
{
	for (int row = 0; row < 20; row++) {
		for (int col = 0; col < 25; col++) {
			map[row][col] = arr[row][col];
		}
	}
}

void Map::DrawMap()
{
	int type = 0;
	for (int row = 0; row < 20; row++) {
		for (int col = 0; col < 25; col++) {
			type = map[row][col];

			destR.x = col * 32;
			destR.y = row * 32;

			switch (type)
			{
			case 0:
				TextureManager::Draw(water, srcR, destR);
				break;
			case 1:
				TextureManager::Draw(grass, srcR, destR);
				break;
			case 2:
				TextureManager::Draw(dirt, srcR, destR);
				break;
			default:
				break;
			}
		}
	}
}
