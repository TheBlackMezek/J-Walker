#include "Box.h"


#include "sfwdraw.h"

#include "Line.h"
#include "TextureLoader.h"



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

void Box::draw(vec2 playerPos, vec2 pos, vec2 size, size_t color)
{
	vec2 botLeft = { pos.x, pos.y };
	vec2 botRight = { pos.x + size.x, pos.y };
	vec2 topLeft = { pos.x, pos.y + size.y };
	vec2 topRight = { pos.x + size.x, pos.y + size.y };
	Line::draw(playerPos, botLeft, botRight, color);
	Line::draw(playerPos, botRight, topRight, color);
	Line::draw(playerPos, topRight, topLeft, color);
	Line::draw(playerPos, topLeft, botLeft, color);
}

void Box::draw(vec2 pos, vec2 size, size_t color)
{
	vec2 botLeft = { pos.x, pos.y };
	vec2 botRight = { pos.x + size.x, pos.y };
	vec2 topLeft = { pos.x, pos.y + size.y };
	vec2 topRight = { pos.x + size.x, pos.y + size.y };
	Line::draw(botLeft, botRight, color);
	Line::draw(botRight, topRight, color);
	Line::draw(topRight, topLeft, color);
	Line::draw(topLeft, botLeft, color);
}

void Box::drawTexture(int texId, vec2 playerPos, vec2 pos, vec2 size, size_t color)
{
	pos.x = 400 - (playerPos.x - pos.x) + size.x / 2;
	pos.y = 300 - (playerPos.y - pos.y) + size.y / 2;

	sfw::drawTexture(texId, pos.x, pos.y, size.x, size.y, 0.0F, true, 0U, color);
}

void Box::drawTexture(int texId, vec2 playerPos, vec2 pos, vec2 size)
{
	pos.x = 400 - (playerPos.x - pos.x) + size.x / 2;
	pos.y = 300 - (playerPos.y - pos.y) + size.y / 2;

	sfw::drawTexture(texId, pos.x, pos.y, size.x, size.y);
}

void Box::drawTexture(int texId, vec2 pos, vec2 size)
{
	pos.x = pos.x + size.x / 2;
	pos.y = pos.y + size.y / 2;

	sfw::drawTexture(texId, pos.x, pos.y, size.x, size.y);
}
