#include "MapRegion.h"


#include <random>

#include "Box.h"
#include "TileRender.h"



MapRegion::MapRegion()
{
	for (int i = 0; i < 100; ++i)
	{
		tiles[i] = rand() % 2 + 1;
	}

	tileSizeAvatar = 40;
	tileSizeWorld = 4;
}


MapRegion::~MapRegion()
{
}



void MapRegion::drawAvatar(vec2 playerPos)
{
	for (int y = 0; y < 10; ++y)
	{
		for (int x = 0; x < 10; ++x)
		{
			TileRender::draw(playerPos,
					{ (float)x * tileSizeAvatar + transform.pos.x * 400,
					  (float)y * tileSizeAvatar + transform.pos.y * 400 },
					{ tileSizeAvatar,tileSizeAvatar },
					  tiles[x + y * 10]);
		}
	}
}

void MapRegion::drawWorld(vec2 playerPos)
{
	for (int y = 0; y < 10; ++y)
	{
		for (int x = 0; x < 10; ++x)
		{
			tiles[x + y * 10];
			TileRender::draw(playerPos,
					{ (float)x * tileSizeWorld + transform.pos.x * 40,
					  (float)y * tileSizeWorld + transform.pos.y * 40 },
					{ tileSizeWorld,tileSizeWorld },
					  tiles[x + y * 10]);
		}
	}
}

//void MapRegion::draw()
//{
//	for (int y = 0; y < 10; ++y)
//	{
//		for (int x = 0; x < 10; ++x)
//		{
//			tiles[x + y * 10];
//			Box::draw({ (float)x * tileSize + transform.pos.x,
//						(float)y * tileSize + transform.pos.y },
//						{ tileSize,tileSize });
//		}
//	}
//}
