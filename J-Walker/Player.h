#pragma once


#include "MathLib\Vec2.h"
#include "MathLib\Transform.h"



class Player
{
public:
	Player();
	~Player();

	vec2 size;
	Transform transform;
	float walkSpeed;


	void update();
	void draw();
};

