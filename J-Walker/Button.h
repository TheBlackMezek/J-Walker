#pragma once


#include "MathLib\Vec2.h"
#include "MathLib\Transform.h"



class Button
{
public:
	Button();
	~Button();

	int imgs[2];

	//vec2 pos;
	Transform transform;
	vec2 size;

	void(*callback)();

	void update();
	void draw();

private:
	bool mouseOver;
};

