#pragma once



#include "MathLib\Transform.h"
#include "MathLib\Vec2.h"

class World;
class City;


class Unit
{
public:
	Unit();
	~Unit();

	Transform transform;
	City* city;

	void update(vec2 playerPos, World& world);
	void draw(vec2 playerPos);
};

