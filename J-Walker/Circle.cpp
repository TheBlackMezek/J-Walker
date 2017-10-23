#include "Circle.h"


#include "sfwdraw.h"


Circle::Circle()
{
}


Circle::~Circle()
{
}



void Circle::draw(vec2 playerPos, vec2 pos, float radius)
{
	vec2 offset;
	offset.x = playerPos.x - pos.x;
	offset.y = playerPos.y - pos.y;
	float dist = magnitude(offset);

	sfw::drawCircle(400 - offset.x,
		300 - offset.y,
		radius);
}

void Circle::draw(vec2 playerPos, vec2 pos, float radius, size_t color)
{
	vec2 offset;
	offset.x = playerPos.x - pos.x;
	offset.y = playerPos.y - pos.y;
	float dist = magnitude(offset);

	sfw::drawCircle(400 - offset.x,
		300 - offset.y,
		radius, 12U, color);
}

void Circle::draw(vec2 pos, float radius, size_t color)
{
	sfw::drawCircle(pos.x, pos.y, radius, 12U, color);
}
