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

	std::vector<MapTile> tileTypes;

	static MapTile get(int type);
	static int num();
	//static void init();
	//static int getImgForType(int type);
};
