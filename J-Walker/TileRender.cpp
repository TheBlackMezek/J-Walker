#include "TileRender.h"


#include "sfwdraw.h"

#include "Box.h"
#include "Line.h"
#include "Circle.h"


TileRender::TileRender()
{
}


TileRender::~TileRender()
{
}



void TileRender::draw(vec2 playerPos, vec2 pos, vec2 size, int type)
{
	vec2 botLeft = { pos.x, pos.y };
	vec2 botRight = { pos.x + size.x, pos.y };
	vec2 topLeft = { pos.x, pos.y + size.y };
	vec2 topRight = { pos.x + size.x, pos.y + size.y };

	switch (type)
	{
	case 1:
		Box::draw(playerPos, pos, size, GREEN);
		Line::draw(playerPos, botLeft, topRight, GREEN);
		Line::draw(playerPos, botRight, topLeft, GREEN);
		break;
	case 2:
		Box::draw(playerPos, pos, size, BLUE);
		Circle::draw(playerPos, {pos.x + size.x/2, pos.y + size.y/2}, size.x / 2, BLUE);
		break;
	default:
		Box::draw(playerPos, pos, size);
		break;
	}
}
