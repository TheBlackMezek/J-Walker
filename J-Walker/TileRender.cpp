#include "TileRender.h"


#include "sfwdraw.h"

#include "Box.h"
#include "Line.h"
#include "Circle.h"
#include "TextureLoader.h"
#include "TileTypes.h"


TileRender::TileRender()
{
}


TileRender::~TileRender()
{
}



void TileRender::draw(vec2 playerPos, vec2 pos, vec2 size, int type, bool worldMode)
{
	vec2 botLeft = { pos.x, pos.y };
	vec2 botRight = { pos.x + size.x, pos.y };
	vec2 topLeft = { pos.x, pos.y + size.y };
	vec2 topRight = { pos.x + size.x, pos.y + size.y };


	if (type == 0)
	{
		Box::draw(playerPos, pos, size);
	}
	else
	{
		Box::drawTexture(TileTypes::get(type).texId, playerPos, pos, size);
	}
}

void TileRender::draw(vec2 pos, vec2 size, int type, bool worldMode)
{
	vec2 botLeft = { pos.x, pos.y };
	vec2 botRight = { pos.x + size.x, pos.y };
	vec2 topLeft = { pos.x, pos.y + size.y };
	vec2 topRight = { pos.x + size.x, pos.y + size.y };

	if (type == 0)
	{
		Box::draw(pos, size);
	}
	else
	{
		Box::drawTexture(TileTypes::get(type).texId, pos, size);
	}
}
