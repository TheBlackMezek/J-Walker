#include "TileRender.h"


#include "sfwdraw.h"

#include "Box.h"
#include "Line.h"
#include "Circle.h"
#include "TextureLoader.h"


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

	switch (type)
	{
	case 1:
		Box::drawTexture(TextureLoader::grassImg, playerPos, pos, size);
		break;
	case 2:
		Box::drawTexture(TextureLoader::waterImg, playerPos, pos, size);
		break;
	default:
		Box::draw(playerPos, pos, size);
		break;
	}
}

void TileRender::draw(vec2 pos, vec2 size, int type, bool worldMode)
{
	vec2 botLeft = { pos.x, pos.y };
	vec2 botRight = { pos.x + size.x, pos.y };
	vec2 topLeft = { pos.x, pos.y + size.y };
	vec2 topRight = { pos.x + size.x, pos.y + size.y };

	switch (type)
	{
	case 1:
		Box::drawTexture(TextureLoader::grassImg, pos, size);
		break;
	case 2:
		Box::drawTexture(TextureLoader::waterImg, pos, size);
		break;
	default:
		Box::draw(pos, size);
		break;
	}
}
