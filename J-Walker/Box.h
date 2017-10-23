#pragma once


#include "MathLib\Vec2.h"



class Box
{
public:
	Box();
	~Box();

	static void draw(vec2 pos, vec2 size);
	static void draw(vec2 playerPos, vec2 pos, vec2 size);
	static void draw(vec2 playerPos, vec2 pos, vec2 size, size_t color);
	static void draw(vec2 pos, vec2 size, size_t color);
};

