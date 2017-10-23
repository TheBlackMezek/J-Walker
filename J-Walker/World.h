#pragma once


#include <vector>

#include "MathLib\Vec2.h"

#include "MapRegion.h"


class World
{
public:
	World();
	~World();

	std::vector<MapRegion> regs;

	void drawAvatar(vec2 playerPos);
	void drawWorld(vec2 playerPos);
	void drawEdit(vec2 reg);
};

