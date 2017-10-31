#include "Unit.h"


#include "World.h"
#include "City.h"
#include "Box.h"
#include "TextureLoader.h"


Unit::Unit()
{
}


Unit::~Unit()
{
}

void Unit::update(vec2 playerPos, World& world)
{
	if (distance(playerPos, transform.pos) < 1200)
	{
		transform.pos += vec2{ (float)(rand() % 3 - 1), (float)(rand() % 3 - 1) };
	}
}

void Unit::draw(vec2 playerPos)
{
	vec2 mid = { transform.pos.x + 16, transform.pos.y + 16 };
	if (mid.x > playerPos.x - 600 && mid.x < playerPos.x + 600
		&& mid.y > playerPos.y - 500 && mid.y < playerPos.y + 500)
	{
		Box::drawTexture(TextureLoader::guyImg, playerPos,
			transform.pos, vec2{ 32, 32 }, city->tint);
	}
}
