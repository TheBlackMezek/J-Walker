#include "World.h"

#include <iostream>

#include "sfwdraw.h"

#include "Circle.h"
#include "Box.h"



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
	float delta = sfw::getDeltaTime();

	for (int i = bullets.size() - 1; i >= 0; --i)
	{
		bool hit = false;

		for (int q = 0; q < enemies.size(); ++q)
		{
			if (pow(bullets[i].pos.x - enemies[q].x, 2) + pow(bullets[i].pos.y - enemies[q].y, 2) < pow(3 + 6, 2))
			{
				hit = true;
				enemies.erase(enemies.begin() + q);
				bullets.erase(bullets.begin() + i);
				break;
			}
		}


		bullets[i].lifeTime += sfw::getDeltaTime();

		if (!hit && bullets[i].lifeTime > bullets[i].lifeMax)
		{
			std::cout << "Erasing" << std::endl;
			bullets.erase(bullets.begin() + i);
		}
		else if(!hit)
		{
			std::cout << "Moving" << std::endl;
			bullets[i].pos = bullets[i].pos + bullets[i].vel;
		}
	}

	for (int i = 0; i < enemies.size(); ++i)
	{
		vec2 vel = normal(playerPos - enemies[i]) * 5;
		enemies[i] = enemies[i] + vel;
	}

	for (int i = 0; i < regs.size(); ++i)
	{
		for (int q = 0; q < 3; ++q)
		{
			if (regs[i].spawners[q].active)
			{
				regs[i].spawners[q].heat -= delta;
				if (regs[i].spawners[q].heat < 0)
				{
					regs[i].spawners[q].heat = 0;
				}
				if (regs[i].spawners[q].heat == 0)
				{
					regs[i].spawners[q].heat = regs[i].spawners[q].cooldown;
					Mat3 m = regs[i].spawners[q].transform.getGlobalTransform();
					vec2 enemy = { m[6], m[7] };
					enemies.push_back(enemy);
				}
			}
		}
	}
}


void World::drawAvatar(vec2 playerPos)
{
	for (int i = 0; i < bullets.size(); ++i)
	{
		Circle::draw(playerPos, bullets[i].pos, 3, RED);
	}

	for (int i = 0; i < enemies.size(); ++i)
	{
		Circle::draw(playerPos, enemies[i], 6, RED);
	}

	for (int i = 0; i < regs.size(); ++i)
	{
		for (int q = 0; q < 3; ++q)
		{
			if (regs[i].spawners[q].active)
			{
				Box::draw(playerPos, regs[i].spawners[q].transform.pos, vec2{ 6, 6 }, RED);
			}
		}
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
