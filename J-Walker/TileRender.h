#pragma once



#include "MathLib\Vec2.h"




class TileRender
{
public:
	TileRender();
	~TileRender();

	static void draw(vec2 playerPos, vec2 pos, vec2 size, int type);
};

