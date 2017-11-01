#pragma once



#include <vector>



struct MapTile
{
	char* name;
	int texId;
	float food;
	float metal;
};



class TileTypes
{
public:
	TileTypes();
	~TileTypes();

	static std::vector<MapTile> tileTypes;

	static void init();
	static int getImgForType(int type);
};

