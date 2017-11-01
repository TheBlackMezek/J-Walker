#pragma once



#include "MathLib\Transform.h"
#include "MathLib\Vec2.h"

class World;


class City
{
public:
	City();
	~City();

	Transform transform;
	size_t tint;



	void update(vec2 playerPos, World& world);
	void draw(vec2 playerPos);
};

