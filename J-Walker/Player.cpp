#include "Player.h"


#include <iostream>

#include "sfwdraw.h"

#include "Box.h"



Player::Player()
{
	size.x = 20;
	size.y = 20;

	walkSpeed = 100;
}


Player::~Player()
{
}



void Player::update()
{
	float delta = sfw::getDeltaTime();

	if (sfw::getKey('W'))
	{
		transform.pos.y += walkSpeed * delta;
	}
	if (sfw::getKey('S'))
	{
		transform.pos.y -= walkSpeed * delta;
	}
	if (sfw::getKey('D'))
	{
		transform.pos.x += walkSpeed * delta;
	}
	if (sfw::getKey('A'))
	{
		transform.pos.x -= walkSpeed * delta;
	}
}

void Player::draw()
{
	Box::draw({ 400 - size.x / 2, 300 - size.y / 2 }, size);
}
