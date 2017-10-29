#pragma once


#include "MathLib\Vec2.h"
#include "MathLib\Transform.h"



struct EnemySpawner
{
	bool usable;
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

	size_t tileCounts[8];
	EnemySpawner spawners[3];
	Transform transform;

	void drawAvatar(vec2 playerPos);
	void drawWorld(vec2 playerPos);
	void setTile(int x, int y, int type);
	void setTile(int idx, int type);
	int getTile(int x, int y);

private:
	size_t tiles[100];
	float tileSizeAvatar;
	float tileSizeWorld;
};

