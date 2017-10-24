
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
	worldModeBut.transform.pos = { 50, 0 };
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
		sfw::drawCircle(sfw::getMouseX(), sfw::getMouseY(), 3);

		if (state == WORLD_STATE)
		{
			player.update();
			avatarModeBut.update();
			genRegBut.update();



			if (newReg.tileCounts[0] != 200)
			{
				switch (newReg.tileCounts[0])
				{
				case 10:
					sfw::drawTexture(TextureLoader::grass10img, 400, 25, 100, 50);
					sfw::drawTexture(TextureLoader::water90img, 500, 25, 100, 50);
					break;
				case 20:
					sfw::drawTexture(TextureLoader::grass20img, 400, 25, 100, 50);
					sfw::drawTexture(TextureLoader::water80img, 500, 25, 100, 50);
					break;
				case 30:
					sfw::drawTexture(TextureLoader::grass30img, 400, 25, 100, 50);
					sfw::drawTexture(TextureLoader::water70img, 500, 25, 100, 50);
					break;
				case 40:
					sfw::drawTexture(TextureLoader::grass40img, 400, 25, 100, 50);
					sfw::drawTexture(TextureLoader::water60img, 500, 25, 100, 50);
					break;
				case 50:
					sfw::drawTexture(TextureLoader::grass50img, 400, 25, 100, 50);
					sfw::drawTexture(TextureLoader::water50img, 500, 25, 100, 50);
					break;
				case 60:
					sfw::drawTexture(TextureLoader::grass60img, 400, 25, 100, 50);
					sfw::drawTexture(TextureLoader::water40img, 500, 25, 100, 50);
					break;
				case 70:
					sfw::drawTexture(TextureLoader::grass70img, 400, 25, 100, 50);
					sfw::drawTexture(TextureLoader::water30img, 500, 25, 100, 50);
					break;
				case 80:
					sfw::drawTexture(TextureLoader::grass80img, 400, 25, 100, 50);
					sfw::drawTexture(TextureLoader::water20img, 500, 25, 100, 50);
					break;
				case 90:
					sfw::drawTexture(TextureLoader::grass90img, 400, 25, 100, 50);
					sfw::drawTexture(TextureLoader::water10img, 500, 25, 100, 50);
					break;
				}

				vec2 selectPos = { sfw::getMouseX() - 400, sfw::getMouseY() - 300 };
				selectPos = selectPos + player.transform.pos;
				selectPos = {floor((selectPos.x) / 40) * 40,
							 floor((selectPos.y) / 40) * 40 };
				Box::draw(player.transform.pos, selectPos, { 40, 40 }, WHITE);

				if (sfw::getMouseButton(0))
				{
					selectPos = selectPos / 40;
					newReg.transform.pos = selectPos;

					bool found = false;
					bool valid = true;

					float goodDist = distance({ 1, 0 }, { 0, 0 });

					for (int i = 0; i < world.regs.size(); ++i)
					{
						vec2 regPos = world.regs[i].transform.pos;
						float dist = distance(regPos, selectPos);
						if (regPos.x == selectPos.x && regPos.y == selectPos.y)
						{
							valid = false;
							break;
						}
						else if (dist == goodDist)
						{
							found = true;
						}
					}

					if (valid && found)
					{
						state = EDIT_STATE;
					}
				}
			}

			avatarModeBut.draw();
			genRegBut.draw();
			world.drawWorld(player.transform.pos);
		}
		else if (state == EDIT_STATE)
		{
			worldModeBut.update();

			worldModeBut.draw();
			newReg.drawAvatar(player.transform.pos + vec2{330, 130});
			world.drawEdit(newReg.transform.pos);
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
	newReg.tileCounts[0] = 200;
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

		newReg.tileCounts[0] = amtGrass;
		newReg.tileCounts[1] = amtWater;
	}
}
