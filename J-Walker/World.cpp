#include "World.h"

#include <iostream>

#include "sfwdraw.h"

#include "Circle.h"



World::World()
{
	MapRegion reg;
	reg.transform.pos = { 0,0 };
	regs.push_back(reg);
}


World::~World()
{
}



void World::update(vec2 playerPos)
{
	for (int i = bullets.size() - 1; i >= 0; --i)
	{
		bullets[i].lifeTime += sfw::getDeltaTime();
		if (bullets[i].lifeTime > bullets[i].lifeMax)
		{
			std::cout << "Erasing" << std::endl;
			bullets.erase(bullets.begin() + i);
		}
		else
		{
			std::cout << "Moving" << std::endl;
			bullets[i].pos = bullets[i].pos + bullets[i].vel;
		}
	}
}


void World::drawAvatar(vec2 playerPos)
{
	for (int i = 0; i < bullets.size(); ++i)
	{
		Circle::draw(playerPos, bullets[i].pos, 3, RED);
	}

	for (int i = 0; i < regs.size(); ++i)
	{
		regs[i].drawAvatar(playerPos);
	}
}

void World::drawWorld(vec2 playerPos)
{
	for (int i = 0; i < regs.size(); ++i)
	{
		regs[i].drawWorld(playerPos);
	}
}

void World::drawEdit(vec2 reg)
{
	vec2 camPos = {reg.x * 400 + 350, reg.y * 400 + 150};

	for (int i = 0; i < regs.size(); ++i)
	{
		regs[i].drawAvatar(camPos);
	}
}
