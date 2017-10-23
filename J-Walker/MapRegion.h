#pragma once


#include "MathLib\Vec2.h"
#include "MathLib\Transform.h"



class MapRegion
{
public:
	MapRegion();
	~MapRegion();

	size_t tiles[100];
	Transform transform;

	void draw(vec2 playerPos);
	void draw();

private:
	float tileSize;
};
