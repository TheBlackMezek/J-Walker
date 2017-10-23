#include "Box.h"


#include "sfwdraw.h"

#include "Line.h"



Box::Box()
{
}


Box::~Box()
{
}



void Box::draw(vec2 pos, vec2 size)
{
	sfw::drawLine(pos.x, pos.y, pos.x, pos.y + size.y);
	sfw::drawLine(pos.x + size.x, pos.y, pos.x + size.x, pos.y + size.y);
	sfw::drawLine(pos.x, pos.y, pos.x + size.x, pos.y);
	sfw::drawLine(pos.x, pos.y + size.y, pos.x + size.x, pos.y + size.y);
}

void Box::draw(vec2 playerPos, vec2 pos, vec2 size)
{
	vec2 botLeft = { pos.x, pos.y };
	vec2 botRight = { pos.x + size.x, pos.y };
	vec2 topLeft = { pos.x, pos.y + size.y };
	vec2 topRight = { pos.x + size.x, pos.y + size.y };
	Line::draw(playerPos, botLeft, botRight);
	Line::draw(playerPos, botRight, topRight);
	Line::draw(playerPos, topRight, topLeft);
	Line::draw(playerPos, topLeft, botLeft);
}
