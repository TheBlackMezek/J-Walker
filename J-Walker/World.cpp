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

	for (int i = 0; i < 10; ++i)
	{
		City city;
		city.transform.pos = { (float)(rand() % 40 - 20) * 40, (float)(rand() % 40 - 20) * 40 };
		int tint = rand() % 5;
		switch (tint)
		{
		case 0:
			city.tint = WHITE;
			break;
		case 1:
			city.tint = RED;
			break;
		case 2:
			city.tint = BLUE;
			break;
		case 3:
			city.tint = GREEN;
			break;
		case 4:
			city.tint = YELLOW;
			break;
		}
		cities.push_back(city);
	}
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
		bullets[i].lifeTime += sfw::getDeltaTime();

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



		if (!hit && bullets[i].lifeTime > bullets[i].lifeMax)
		{
			bullets.erase(bullets.begin() + i);
		}
		else if(!hit)
		{
			bullets[i].pos = bullets[i].pos + bullets[i].vel * delta;
		}
	}

	for (int i = 0; i < cities.size(); ++i)
	{
		cities[i].update(playerPos, *this);
	}

	for (int i = 0; i < units.size(); ++i)
	{
		units[i].update(playerPos, *this);
	}

	for (int i = 0; i < enemies.size(); ++i)
	{
		vec2 vel = normal(playerPos - enemies[i]) * 40 * delta;
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
					if (distance(playerPos, regs[i].spawners[q].transform.pos) < 600)
					{
						vec2 enemy = regs[i].spawners[q].transform.pos + regs[i].transform.pos * 400;
						enemies.push_back(enemy);
					}
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

	for (int i = 0; i < cities.size(); ++i)
	{
		cities[i].draw(playerPos);
	}

	for (int i = 0; i < units.size(); ++i)
	{
		units[i].draw(playerPos);
	}

	for (int i = 0; i < enemies.size(); ++i)
	{
		Circle::draw(playerPos, enemies[i], 6, RED);
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
