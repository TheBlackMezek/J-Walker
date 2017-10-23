#include "TextureLoader.h"

#include "sfwdraw.h"


int TextureLoader::avatar_button_1;
int TextureLoader::avatar_button_2;
int TextureLoader::back_button_1;
int TextureLoader::back_button_2;
int TextureLoader::gen_button_1;
int TextureLoader::gen_button_2;

TextureLoader::TextureLoader()
{
	
}


TextureLoader::~TextureLoader()
{
}

void TextureLoader::init()
{
	avatar_button_1 = sfw::loadTextureMap("AvatarButton1.png");
	avatar_button_2 = sfw::loadTextureMap("AvatarButton2.png");
	back_button_1 = sfw::loadTextureMap("BackButton1.png");
	back_button_2 = sfw::loadTextureMap("BackButton2.png");
	gen_button_1 = sfw::loadTextureMap("GenButton1.png");
	gen_button_2 = sfw::loadTextureMap("GenButton2.png");
}
