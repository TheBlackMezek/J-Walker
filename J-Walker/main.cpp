
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
int editTileType = 0;


void switchToAvatarMode();
void switchToWorldMode();
void genRegion();
void selectGrass();
void selectWater();
void selectEmpty();
void selectSpawnOne();
void selectSpawnTwo();
void selectSpawnThree();




int main()
{
	srand(time(NULL));



	sfw::initContext(800, 600, "J-Walker");

	sfw::setBackgroundColor(BLACK);

	TextureLoader::init();

	newReg.tileCounts[0] = 0;



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

	Button grassTileBut;
	grassTileBut.transform.pos = { 400, 25 };
	grassTileBut.size = { 100, 50 };
	grassTileBut.transform.disfigure = grassTileBut.size;
	grassTileBut.callback = &selectGrass;
	grassTileBut.useColors = true;
	grassTileBut.colors[0] = WHITE;
	grassTileBut.colors[1] = GREEN;

	Button waterTileBut;
	waterTileBut.transform.pos = { 500, 25 };
	waterTileBut.size = { 100, 50 };
	waterTileBut.transform.disfigure = waterTileBut.size;
	waterTileBut.callback = &selectWater;
	waterTileBut.useColors = true;
	waterTileBut.colors[0] = WHITE;
	waterTileBut.colors[1] = BLUE;

	Button emptyTileBut;
	emptyTileBut.transform.pos = { 600, 25 };
	emptyTileBut.size = { 50, 50 };
	emptyTileBut.transform.disfigure = emptyTileBut.size;
	emptyTileBut.callback = &selectEmpty;
	emptyTileBut.imgs[0] = TextureLoader::empty_tile_img;
	emptyTileBut.imgs[1] = TextureLoader::empty_tile_img;
	emptyTileBut.useColors = true;
	emptyTileBut.colors[0] = WHITE;
	emptyTileBut.colors[1] = GREEN;

	Button spawnerButOne;
	spawnerButOne.transform.pos = { 650, 25 };
	spawnerButOne.size = { 50, 50 };
	spawnerButOne.transform.disfigure = spawnerButOne.size;
	spawnerButOne.callback = &selectSpawnOne;
	spawnerButOne.imgs[0] = TextureLoader::spawner_button;
	spawnerButOne.imgs[1] = TextureLoader::spawner_button;
	spawnerButOne.useColors = true;
	spawnerButOne.colors[0] = WHITE;
	spawnerButOne.colors[1] = RED;

	Button spawnerButTwo;
	spawnerButTwo.transform.pos = { 700, 25 };
	spawnerButTwo.size = { 50, 50 };
	spawnerButTwo.transform.disfigure = spawnerButTwo.size;
	spawnerButTwo.callback = &selectSpawnTwo;
	spawnerButTwo.imgs[0] = TextureLoader::spawner_button;
	spawnerButTwo.imgs[1] = TextureLoader::spawner_button;
	spawnerButTwo.useColors = true;
	spawnerButTwo.colors[0] = WHITE;
	spawnerButTwo.colors[1] = RED;

	Button spawnerButThree;
	spawnerButThree.transform.pos = { 750, 25 };
	spawnerButThree.size = { 50, 50 };
	spawnerButThree.transform.disfigure = spawnerButThree.size;
	spawnerButThree.callback = &selectSpawnThree;
	spawnerButThree.imgs[0] = TextureLoader::spawner_button;
	spawnerButThree.imgs[1] = TextureLoader::spawner_button;
	spawnerButThree.useColors = true;
	spawnerButThree.colors[0] = WHITE;
	spawnerButThree.colors[1] = RED;

	


	while (sfw::stepContext())
	{
		sfw::drawCircle(sfw::getMouseX(), sfw::getMouseY(), 3);

		if (state == WORLD_STATE)
		{
			player.update();
			avatarModeBut.update();
			genRegBut.update();



			if (newReg.tileCounts[0] != 0)
			{
				switch (newReg.tileCounts[1])
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

				if (newReg.spawners[0].usable)
				{
					spawnerButOne.draw();
				}
				if (newReg.spawners[1].usable)
				{
					spawnerButTwo.draw();
				}
				if (newReg.spawners[2].usable)
				{
					spawnerButThree.draw();
				}


				vec2 gridPos = selectPos / 40;
				newReg.transform.pos = gridPos;

				bool found = false;
				bool valid = true;

				float goodDist = distance({ 1, 0 }, { 0, 0 });

				for (int i = 0; i < world.regs.size(); ++i)
				{
					vec2 regPos = world.regs[i].transform.pos;
					float dist = distance(regPos, gridPos);
					if (regPos.x == gridPos.x && regPos.y == gridPos.y)
					{
						valid = false;
						break;
					}
					else if (dist == goodDist)
					{
						found = true;
					}
				}


				if (sfw::getMouseButton(0))
				{

					if (valid && found)
					{
						state = EDIT_STATE;
						switch (newReg.tileCounts[1])
						{
						case 10:
							grassTileBut.imgs[0] = TextureLoader::grass10img;
							grassTileBut.imgs[1] = TextureLoader::grass10img;
							waterTileBut.imgs[0] = TextureLoader::water90img;
							waterTileBut.imgs[1] = TextureLoader::water90img;
							break;
						case 20:
							grassTileBut.imgs[0] = TextureLoader::grass20img;
							grassTileBut.imgs[1] = TextureLoader::grass20img;
							waterTileBut.imgs[0] = TextureLoader::water80img;
							waterTileBut.imgs[1] = TextureLoader::water80img;
							break;
						case 30:
							grassTileBut.imgs[0] = TextureLoader::grass30img;
							grassTileBut.imgs[1] = TextureLoader::grass30img;
							waterTileBut.imgs[0] = TextureLoader::water70img;
							waterTileBut.imgs[1] = TextureLoader::water70img;
							break;
						case 40:
							grassTileBut.imgs[0] = TextureLoader::grass40img;
							grassTileBut.imgs[1] = TextureLoader::grass40img;
							waterTileBut.imgs[0] = TextureLoader::water60img;
							waterTileBut.imgs[1] = TextureLoader::water60img;
							break;
						case 50:
							grassTileBut.imgs[0] = TextureLoader::grass50img;
							grassTileBut.imgs[1] = TextureLoader::grass50img;
							waterTileBut.imgs[0] = TextureLoader::water50img;
							waterTileBut.imgs[1] = TextureLoader::water50img;
							break;
						case 60:
							grassTileBut.imgs[0] = TextureLoader::grass60img;
							grassTileBut.imgs[1] = TextureLoader::grass60img;
							waterTileBut.imgs[0] = TextureLoader::water40img;
							waterTileBut.imgs[1] = TextureLoader::water40img;
							break;
						case 70:
							grassTileBut.imgs[0] = TextureLoader::grass70img;
							grassTileBut.imgs[1] = TextureLoader::grass70img;
							waterTileBut.imgs[0] = TextureLoader::water30img;
							waterTileBut.imgs[1] = TextureLoader::water30img;
							break;
						case 80:
							grassTileBut.imgs[0] = TextureLoader::grass80img;
							grassTileBut.imgs[1] = TextureLoader::grass80img;
							waterTileBut.imgs[0] = TextureLoader::water20img;
							waterTileBut.imgs[1] = TextureLoader::water20img;
							break;
						case 90:
							grassTileBut.imgs[0] = TextureLoader::grass90img;
							grassTileBut.imgs[1] = TextureLoader::grass90img;
							waterTileBut.imgs[0] = TextureLoader::water10img;
							waterTileBut.imgs[1] = TextureLoader::water10img;
							break;
						}
					}
				}

				int drawColor = (valid && found) ? GREEN : WHITE;

				Box::draw(player.transform.pos, selectPos, { 40, 40 }, drawColor);

			}

			avatarModeBut.draw();
			genRegBut.draw();
			world.drawWorld(player.transform.pos);
		}
		else if (state == EDIT_STATE)
		{
			if (newReg.tileCounts[1] == 0 && newReg.tileCounts[2] == 0)
			{
				worldModeBut.update();
			}
			grassTileBut.update();
			waterTileBut.update();
			emptyTileBut.update();
			if (newReg.spawners[0].usable)
			{
				spawnerButOne.update();
			}
			if (newReg.spawners[1].usable)
			{
				spawnerButTwo.update();
			}
			if (newReg.spawners[2].usable)
			{
				spawnerButThree.update();
			}

			
			vec2 selectPos = { sfw::getMouseX(), sfw::getMouseY() };
			selectPos = { floor((selectPos.x - 10) / 40) * 40 + 10,
				floor((selectPos.y + 10) / 40) * 40 - 10 };
			//Box::draw(selectPos, { 40, 40 }, WHITE);
			vec2 regPos = { (selectPos.x - 50) / 40, (selectPos.y - 150) / 40 };

			if (sfw::getMouseButton(0) && regPos.x >= 0 && regPos.x < 10 && regPos.y >= 0 && regPos.y < 10)
			{
				if (editTileType < 3 && newReg.tileCounts[editTileType] > 0)
				{
					++newReg.tileCounts[newReg.getTile((int)regPos.x, (int)regPos.y)];
					newReg.setTile((int)regPos.x, (int)regPos.y, editTileType);
					--newReg.tileCounts[editTileType];
				}
				else if(editTileType >= 3)
				{
					newReg.spawners[editTileType - 3].active = true;
					newReg.spawners[editTileType - 3].transform.pos = vec2{ regPos.x * 40 + 20, regPos.y * 40 + 20 };
				}
			}


			if (newReg.tileCounts[1] == 0 && newReg.tileCounts[2] == 0)
			{
				worldModeBut.draw();
			}
			grassTileBut.draw();
			waterTileBut.draw();
			emptyTileBut.draw();
			if (newReg.spawners[0].usable)
			{
				spawnerButOne.draw();
			}
			if (newReg.spawners[1].usable)
			{
				spawnerButTwo.draw();
			}
			if (newReg.spawners[2].usable)
			{
				spawnerButThree.draw();
			}
			newReg.drawAvatar({ newReg.transform.pos.x * 400 + 350, newReg.transform.pos.y * 400 + 150 });
			world.drawEdit(newReg.transform.pos);
		}
		else if (state == PLAY_STATE)
		{
			player.update();
			if (sfw::getMouseButton(0) && player.gunHeat == 0)
			{
				player.gunHeat = player.gunCooldown;
				Bullet b;
				b.pos = player.transform.pos;
				vec2 v = { sfw::getMouseX(), sfw::getMouseY() };
				v = v - vec2{400, 300};
				v = normal(v) * 400;
				b.vel = v;
				b.lifeTime = 0;
				b.lifeMax = 2;
				world.bullets.push_back(b);
			}
			world.update(player.transform.pos);

			for (int i = 0; i < world.enemies.size(); ++i)
			{
				if (distance(world.enemies[i], player.transform.pos) < 13)
				{
					state = WORLD_STATE;
					player.transform.pos = { 20, 20 };
				}
			}



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
	player.gunHeat = player.gunCooldown;
	world.enemies.clear();
	world.bullets.clear();
	for (int i = 0; i < world.regs.size(); ++i)
	{
		for (int q = 0; q < 3; ++q)
		{
			world.regs[i].spawners[q].heat = (rand() % (int)(world.regs[i].spawners[q].cooldown * 1000)) / 1000.0f;
		}
	}
}

void switchToWorldMode()
{
	state = WORLD_STATE;
	player.transform.pos = { 20,20 };
	newReg.tileCounts[0] = 0;
	editTileType = 0;
	world.regs.push_back(newReg);
}

void genRegion()
{
	if (newReg.tileCounts[0] == 0)
	{
		for (int i = 0; i < 100; ++i)
		{
			newReg.setTile(i, 0);
		}
		for (int i = 0; i < 3; ++i)
		{
			newReg.spawners[i].active = false;
			newReg.spawners[i].usable = false;
		}

		int amtGrass = rand() % 9 + 1;
		amtGrass *= 10;

		int amtWater = 100 - amtGrass;

		newReg.tileCounts[0] = 200;
		newReg.tileCounts[1] = amtGrass;
		newReg.tileCounts[2] = amtWater;

		int spawners = rand() % 4;
		for (int i = 0; i < spawners; ++i)
		{
			newReg.spawners[i].usable = true;
		}
	}
}

void selectGrass()
{
	editTileType = 1;
}

void selectWater()
{
	editTileType = 2;
}

void selectEmpty()
{
	editTileType = 0;
}

void selectSpawnOne()
{
	editTileType = 3;
	newReg.spawners[0].active = false;
}

void selectSpawnTwo()
{
	editTileType = 4;
	newReg.spawners[1].active = false;
}

void selectSpawnThree()
{
	editTileType = 5;
	newReg.spawners[2].active = false;
}
