#include "TextureLoader.h"

#include "sfwdraw.h"


int TextureLoader::stringBitmap;

int TextureLoader::avatar_button_1;
int TextureLoader::avatar_button_2;
int TextureLoader::back_button_1;
int TextureLoader::back_button_2;
int TextureLoader::gen_button_1;
int TextureLoader::gen_button_2;

int TextureLoader::empty_tile_img;
int TextureLoader::spawner_button;

int TextureLoader::grassImg;
int TextureLoader::waterImg;
int TextureLoader::forestImg;
int TextureLoader::mountainImg;
int TextureLoader::hillImg;
int TextureLoader::desertImg;
int TextureLoader::marshImg;

int TextureLoader::leftArrowImg;
int TextureLoader::rightArrowImg;

int TextureLoader::cityImg;
int TextureLoader::guyImg;



TextureLoader::TextureLoader()
{
	
}


TextureLoader::~TextureLoader()
{
}

void TextureLoader::init()
{
	stringBitmap = sfw::loadTextureMap("16x16fontmap.gif", 16, 16);

	avatar_button_1 = sfw::loadTextureMap("AvatarButton1.png");
	avatar_button_2 = sfw::loadTextureMap("AvatarButton2.png");
	back_button_1 = sfw::loadTextureMap("BackButton1.png");
	back_button_2 = sfw::loadTextureMap("BackButton2.png");
	gen_button_1 = sfw::loadTextureMap("GenButton1.png");
	gen_button_2 = sfw::loadTextureMap("GenButton2.png");

	empty_tile_img = sfw::loadTextureMap("EmptyTile.png");
	spawner_button = sfw::loadTextureMap("SpawnerButton.png");

	grassImg = sfw::loadTextureMap("GrassTile.png");
	waterImg = sfw::loadTextureMap("WaterTile.png");
	forestImg = sfw::loadTextureMap("ForestTile.png");
	mountainImg = sfw::loadTextureMap("MountainTile.png");
	hillImg = sfw::loadTextureMap("HillTile.png");
	grassImg = sfw::loadTextureMap("GrassTile.png");
	desertImg = sfw::loadTextureMap("DesertTile.png");
	marshImg = sfw::loadTextureMap("MarshTile.png");

	leftArrowImg = sfw::loadTextureMap("LeftArrow.png");
	rightArrowImg = sfw::loadTextureMap("RightArrow.png");

	cityImg = sfw::loadTextureMap("CityImg.png");
	guyImg = sfw::loadTextureMap("GuyImg.png");
}
