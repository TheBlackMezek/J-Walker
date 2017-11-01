#pragma once



#include "MathLib\Transform.h"
#include "MathLib\Vec2.h"

class World;


class City
{
public:
	City(World& world);
	~City();

	Transform transform;
	size_t tint;
	float food;
	float foodProd;
	float metal;
	float metalProd;


	void update(vec2 playerPos, World& world, float dt);
	void draw(vec2 playerPos);
	
	void setProd(World& world);
};

