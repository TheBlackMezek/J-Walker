#pragma once


#include "MathLib\Vec2.h"



class Circle
{
public:
	Circle();
	~Circle();

	static void draw(vec2 playerPos, vec2 pos, float radius);
	static void draw(vec2 playerPos, vec2 pos, float radius, size_t color);
};

