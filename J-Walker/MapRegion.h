#pragma once


#include "MathLib\Vec2.h"
#include "MathLib\Transform.h"



class MapRegion
{
public:
	MapRegion();
	~MapRegion();

	size_t tiles[100];
	size_t tileCounts[2];
	Transform transform;

	void drawAvatar(vec2 playerPos);
	void drawWorld(vec2 playerPos);

private:
	float tileSizeAvatar;
	float tileSizeWorld;
};

