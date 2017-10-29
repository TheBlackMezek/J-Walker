#include "MapRegion.h"


#include <random>

#include "sfwdraw.h"

#include "Box.h"
#include "TileRender.h"



MapRegion::MapRegion()
{
	for (int i = 0; i < 100; ++i)
	{
		//tiles[i] = rand() % 2 + 1;
		tiles[i] = 1;
	}

	for (int i = 0; i < 8; ++i)
	{
		tileCounts[i] = 0;
	}

	for (int i = 0; i < 3; ++i)
	{
		spawners[i].usable = false;
		spawners[i].active = false;
		spawners[i].transform.parent = &transform;
		spawners[i].cooldown = 10;
		spawners[i].heat = (rand() % (int)(spawners[i].cooldown * 1000)) / 1000.0f;
	}

	tileSizeAvatar = 40;
	tileSizeWorld = 4;
}


MapRegion::~MapRegion()
{
}



void MapRegion::drawAvatar(vec2 playerPos)
{
	vec2 mid = { transform.pos.x * 400 + 200, transform.pos.y * 400 + 200 };
	if (	mid.x > playerPos.x - 600 && mid.x < playerPos.x + 600
		&&	mid.y > playerPos.y - 500 && mid.y < playerPos.y + 500)
	//if (distance({transform.pos.x * 400 + 200, transform.pos.y * 400 + 200}, playerPos) < 800)
	{
		for (int q = 0; q < 3; ++q)
		{
			if (spawners[q].active)
			{
				Box::draw(playerPos, spawners[q].transform.pos + transform.pos * 400, vec2{ 6, 6 }, RED);
			}
		}

		for (int y = 0; y < 10; ++y)
		{
			for (int x = 0; x < 10; ++x)
			{
				TileRender::draw(playerPos,
				{ (float)x * tileSizeAvatar + transform.pos.x * 400,
				  (float)y * tileSizeAvatar + transform.pos.y * 400 },
				  { tileSizeAvatar,tileSizeAvatar },
					tiles[x + y * 10], false);
			}
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
					  tiles[x + y * 10], true);
		}
	}
}

void MapRegion::setTile(int x, int y, int type)
{
	setTile(x + y * 10, type);
}

void MapRegion::setTile(int idx, int type)
{
	tiles[idx] = type;
}

int MapRegion::getTile(int x, int y)
{
	return tiles[x + y * 10];
}

int MapRegion::getTile(int idx)
{
	return tiles[idx];
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
