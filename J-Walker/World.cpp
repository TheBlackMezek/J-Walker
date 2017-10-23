#include "World.h"



World::World()
{
	MapRegion reg;
	reg.transform.pos = { 0,0 };
	regs.push_back(reg);
}


World::~World()
{
}


void World::drawAvatar(vec2 playerPos)
{
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
