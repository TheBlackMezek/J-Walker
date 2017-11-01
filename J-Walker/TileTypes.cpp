#include "TileTypes.h"


#include "TextureLoader.h"




std::vector<MapTile> TileTypes::tileTypes;




TileTypes::TileTypes()
{
}


TileTypes::~TileTypes()
{
}


void TileTypes::init()
{
	MapTile empty;
	empty.name = "empty";
	empty.texId = TextureLoader::empty_tile_img;
	empty.food = 0;
	empty.metal = 0;
	tileTypes.push_back(empty);

	MapTile grass;
	grass.name = "grass";
	grass.texId = TextureLoader::grassImg;
	grass.food = 10;
	grass.metal = 1;
	tileTypes.push_back(grass);

	MapTile water;
	water.name = "water";
	water.texId = TextureLoader::waterImg;
	water.food = 20;
	water.metal = 0;
	tileTypes.push_back(water);

	MapTile forest;
	forest.name = "forest";
	forest.texId = TextureLoader::forestImg;
	forest.food = 12;
	forest.metal = 0;
	tileTypes.push_back(forest);

	MapTile mountain;
	mountain.name = "mountain";
	mountain.texId = TextureLoader::mountainImg;
	mountain.food = 0.1f;
	mountain.metal = 10;
	tileTypes.push_back(mountain);

	MapTile desert;
	desert.name = "desert";
	desert.texId = TextureLoader::desertImg;
	desert.food = 0.25f;
	desert.metal = 2;
	tileTypes.push_back(desert);

	MapTile hill;
	hill.name = "hill";
	hill.texId = TextureLoader::hillImg;
	hill.food = 0.75f;
	hill.metal = 1.5f;
	tileTypes.push_back(hill);

	MapTile marsh;
	marsh.name = "marsh";
	marsh.texId = TextureLoader::marshImg;
	marsh.food = 2;
	marsh.metal = 0;
	tileTypes.push_back(marsh);
}

int TileTypes::getImgForType(int type)
{
	
	return tileTypes[type].texId;
}
