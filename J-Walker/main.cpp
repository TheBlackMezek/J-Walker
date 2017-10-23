
#include <iostream>
#include <time.h>

#include "sfwdraw.h"
#include "MathLib\Transform.h"

#include "Player.h"
#include "Box.h"
#include "Circle.h"
#include "World.h"
#include "Button.h"
#include "TextureLoader.h"




enum GameState
{
	WORLD_STATE,
	EDIT_STATE,
	PLAY_STATE
};


GameState state = WORLD_STATE;
Player player;
World world;
MapRegion newReg;


void switchToAvatarMode();
void switchToWorldMode();
void genRegion();




int main()
{
	srand(time(NULL));



	sfw::initContext(800, 600, "J-Walker");

	sfw::setBackgroundColor(BLACK);

	TextureLoader::init();

	newReg.tileCounts[0] = 200;



	player.transform.pos = { 20, 20 };



	Button avatarModeBut;
	avatarModeBut.transform.pos = { 0, 0 };
	avatarModeBut.callback = &switchToAvatarMode;
	avatarModeBut.imgs[0] = TextureLoader::avatar_button_1;
	avatarModeBut.imgs[1] = TextureLoader::avatar_button_2;

	Button worldModeBut;
	worldModeBut.transform.pos = { 0, 0 };
	worldModeBut.callback = &switchToWorldMode;
	worldModeBut.imgs[0] = TextureLoader::back_button_1;
	worldModeBut.imgs[1] = TextureLoader::back_button_2;

	Button genRegBut;
	genRegBut.transform.pos = { 100, 0 };
	genRegBut.size = { 100, 50 };
	genRegBut.transform.disfigure = genRegBut.size;
	genRegBut.callback = &genRegion;
	genRegBut.imgs[0] = TextureLoader::gen_button_1;
	genRegBut.imgs[1] = TextureLoader::gen_button_2;

	


	while (sfw::stepContext())
	{
		if (state == WORLD_STATE)
		{
			player.update();
			avatarModeBut.update();
			genRegBut.update();

			world.drawWorld(player.transform.pos);
			avatarModeBut.draw();
			genRegBut.draw();
		}
		else if (state == EDIT_STATE)
		{
			worldModeBut.update();

			worldModeBut.draw();
		}
		else if (state == PLAY_STATE)
		{
			player.update();

			world.drawAvatar(player.transform.pos);
			player.draw();

			if (sfw::getKey(KEY_ESCAPE))
			{
				state = WORLD_STATE;
				player.transform.pos = { 20,20 };
			}
		}

		sfw::drawCircle(sfw::getMouseX(), sfw::getMouseY(), 3);
	}


	return 0;
}




void switchToAvatarMode()
{
	state = PLAY_STATE;
	player.transform.pos = { 100,100 };
}

void switchToWorldMode()
{
	state = WORLD_STATE;
	player.transform.pos = { 20,20 };
}

void genRegion()
{
	if (newReg.tileCounts[0] == 200)
	{
		for (int i = 0; i < 100; ++i)
		{
			newReg.tiles[i] = 0;
		}

		int amtGrass = rand() % 9 + 1;
		amtGrass *= 10;

		int amtWater = 100 - amtGrass;
	}
}
