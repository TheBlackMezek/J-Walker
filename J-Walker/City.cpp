#include "City.h"

#include "sfwdraw.h"

#include "World.h"
#include "Box.h"
#include "TextureLoader.h"
#include "Unit.h"


City::City()
{
	tint = WHITE;
}


City::~City()
{
}

void City::update(vec2 playerPos, World& world)
{
	if (distance(playerPos, transform.pos) < 1200)
	{
		if (rand() % 1000 == 0)
		{
			Unit unit;
			unit.transform.pos = transform.pos;
			unit.city = this;
			world.units.push_back(unit);
		}
	}
}

void City::draw(vec2 playerPos)
{
	vec2 mid = { transform.pos.x + 16, transform.pos.y + 16 };
	if (mid.x > playerPos.x - 600 && mid.x < playerPos.x + 600
		&& mid.y > playerPos.y - 500 && mid.y < playerPos.y + 500)
	{
		Box::drawTexture(TextureLoader::cityImg, playerPos,
			transform.pos, vec2{ 32, 32 }, tint);
	}
	Box::drawTexture(TextureLoader::cityImg, playerPos,
		transform.pos, vec2{ 32, 32 }, tint);
}
