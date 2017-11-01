#include "City.h"

#include <iostream>
#include "sfwdraw.h"

#include "World.h"
#include "Box.h"
#include "TextureLoader.h"
#include "Unit.h"
#include "TileTypes.h"


City::City(World& world)
{
	tint = WHITE;

	foodProd = 0;
	metalProd = 0;
	food = 0;
	metal = 0;

	//setProd(world);
}


City::~City()
{
}

void City::update(vec2 playerPos, World& world, float dt)
{
	if (distance(playerPos, transform.pos) < 1200)
	{
		metal += metalProd * dt;
		food += foodProd * dt + foodProd * metal * dt;

		if (food > 10)
		{
			food -= 10;
			metal -= 1;

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



void City::setProd(World& world)
{
	foodProd = 0;
	metalProd = 0;
	//vec2 gridpos = vec2{ transform.pos.x / 40, transform.pos.y / 40 };
	vec2 gridpos;
	gridpos.x = transform.pos.x / 40;
	gridpos.y = transform.pos.y / 40;
	this;
	for (int x = gridpos.x - 1; x <= gridpos.x + 1; ++x)
	{
		for (int y = gridpos.y - 1; y <= gridpos.y + 1; ++y)
		{
			MapTile t = TileTypes::get(world.getTile(x, y));
			foodProd += t.food;
			metalProd += t.metal;
		}
	}
}
