#pragma once


#include "MathLib\Vec2.h"
#include "MathLib\Transform.h"



struct EnemySpawner
{
	bool active;
	Transform transform;
	float heat;
	float cooldown;
};


class MapRegion
{
public:
	MapRegion();
	~MapRegion();

	size_t tiles[100];
	size_t tileCounts[3];
	EnemySpawner spawners[3];
	Transform transform;

	void drawAvatar(vec2 playerPos);
	void drawWorld(vec2 playerPos);

private:
	float tileSizeAvatar;
	float tileSizeWorld;
};

