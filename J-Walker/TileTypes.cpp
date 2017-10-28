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
	tileTypes.push_back(empty);

	MapTile grass;
	grass.name = "grass";
	grass.texId = TextureLoader::grassImg;
	tileTypes.push_back(grass);

	MapTile water;
	water.name = "water";
	water.texId = TextureLoader::waterImg;
	tileTypes.push_back(water);

	MapTile forest;
	forest.name = "forest";
	forest.texId = TextureLoader::forestImg;
	tileTypes.push_back(forest);

	MapTile mountain;
	mountain.name = "mountain";
	mountain.texId = TextureLoader::mountainImg;
	tileTypes.push_back(mountain);

	MapTile desert;
	desert.name = "desert";
	desert.texId = TextureLoader::desertImg;
	tileTypes.push_back(desert);

	MapTile hill;
	hill.name = "hill";
	hill.texId = TextureLoader::hillImg;
	tileTypes.push_back(hill);

	MapTile marsh;
	marsh.name = "marsh";
	marsh.texId = TextureLoader::marshImg;
	tileTypes.push_back(marsh);
}

int TileTypes::getImgForType(int type)
{
	
	return tileTypes[type].texId;
}
