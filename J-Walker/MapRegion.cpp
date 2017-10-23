#include "MapRegion.h"



#include "Box.h"



MapRegion::MapRegion()
{
	for (int i = 0; i < 100; ++i)
	{
		tiles[i] = 1;
	}

	tileSize = 40;
	transform.pos = { 50, 150 };
}


MapRegion::~MapRegion()
{
}



void MapRegion::draw(vec2 playerPos)
{
	for (int y = 0; y < 10; ++y)
	{
		for (int x = 0; x < 10; ++x)
		{
			tiles[x + y * 10];
			Box::draw(playerPos, { (float)x * tileSize, (float)y * tileSize }, { tileSize,tileSize });
		}
	}
}

void MapRegion::draw()
{
	for (int y = 0; y < 10; ++y)
	{
		for (int x = 0; x < 10; ++x)
		{
			tiles[x + y * 10];
			Box::draw({ (float)x * tileSize + transform.pos.x,
						(float)y * tileSize + transform.pos.y },
						{ tileSize,tileSize });
		}
	}
}
