#pragma once




class TextureLoader
{
public:
	 TextureLoader();
	~TextureLoader();



	static int stringBitmap;

	static int avatar_button_1;
	static int avatar_button_2;

	static int back_button_1;
	static int back_button_2;
	
	static int gen_button_1;
	static int gen_button_2;

	static int empty_tile_img;
	static int spawner_button;

	static int grassImg;
	static int waterImg;
	static int forestImg;
	static int mountainImg;
	static int hillImg;
	static int desertImg;
	static int marshImg;
	
	static int leftArrowImg;
	static int rightArrowImg;


	static void init();
};

