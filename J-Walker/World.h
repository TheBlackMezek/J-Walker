#pragma once


#include <vector>

#include "MathLib\Vec2.h"

#include "MapRegion.h"



struct Bullet
{
	float lifeTime;
	float lifeMax;
	vec2 pos;
	vec2 vel;
};


class World
{
public:
	World();
	~World();

	std::vector<MapRegion> regs;
	std::vector<Bullet> bullets;


	void update(vec2 playerPos);

	void drawAvatar(vec2 playerPos);
	void drawWorld(vec2 playerPos);
	void drawEdit(vec2 reg);
};

