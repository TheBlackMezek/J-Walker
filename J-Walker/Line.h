#pragma once


#include "MathLib\Vec2.h"



class Line
{
public:
	Line();
	~Line();


	static void draw(vec2 playerPos, vec2 start, vec2 end);
	static void draw(vec2 playerPos, vec2 start, vec2 end, size_t color);

};

