
#include <iostream>
#include <time.h>
#include <string>
#include <fstream>
#include <vector>

#include "sfwdraw.h"
#include "MathLib\Transform.h"

#include "Player.h"
#include "Box.h"
#include "Circle.h"
#include "World.h"
#include "Button.h"
#include "TextureLoader.h"
#include "TileTypes.h"
#include "MouseHandler.h"




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
bool usingCard = false;
int editTileType = 0;
int editSpawner = 0;
bool editTilesNotEntities = true;
std::string newRegionDesc = "Not set";
std::vector<int> deck;
int deckIdx = -1;
int newCardType = 1;

Button tileTypeBut;
Button cardTypeBut;


void switchToAvatarMode();
void switchToWorldMode();
void genRegion(int type);
void selectGrass();
void selectWater();
void selectEmpty();
void selectSpawnOne();
void selectSpawnTwo();
void selectSpawnThree();

void drawCard();
void nextCardType();
void prevCardType();
void setCardType();

void previousTileType();
void nextTileType();
void selectTiles();

void saveWorld();
void loadWorld();

void shuffleDeck();




int main()
{
	srand(time(NULL));



	sfw::initContext(800, 600, "J-Walker");

	sfw::setBackgroundColor(BLACK);

	TextureLoader::init();
	TileTypes::init();
	MouseHandler::init();

	newReg.tileCounts[0] = -1;
	deck.push_back(1);
	deck.push_back(1);
	deck.push_back(2);
	deck.push_back(2);
	shuffleDeck();
	deck.push_back(0);



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
	genRegBut.callback = &drawCard;
	genRegBut.imgs[0] = TextureLoader::gen_button_1;
	genRegBut.imgs[1] = TextureLoader::gen_button_2;

	//Button tileTypeBut;
	tileTypeBut.transform.pos = { 450, 25 };
	tileTypeBut.size = { 50, 50 };
	tileTypeBut.transform.disfigure = tileTypeBut.size;
	tileTypeBut.callback = selectTiles;
	tileTypeBut.useColors = true;
	tileTypeBut.imgs[0] = TextureLoader::empty_tile_img;
	tileTypeBut.imgs[1] = TextureLoader::empty_tile_img;
	tileTypeBut.colors[0] = WHITE;
	tileTypeBut.colors[1] = GREEN;

	Button prevTileBut;
	prevTileBut.transform.pos = { 400, 25 };
	prevTileBut.size = { 50, 50 };
	prevTileBut.transform.disfigure = prevTileBut.size;
	prevTileBut.callback = &previousTileType;
	prevTileBut.useColors = true;
	prevTileBut.imgs[0] = TextureLoader::leftArrowImg;
	prevTileBut.imgs[1] = TextureLoader::leftArrowImg;
	prevTileBut.colors[0] = WHITE;
	prevTileBut.colors[1] = GREEN;

	Button nextTileBut;
	nextTileBut.transform.pos = { 500, 25 };
	nextTileBut.size = { 50, 50 };
	nextTileBut.transform.disfigure = nextTileBut.size;
	nextTileBut.callback = &nextTileType;
	nextTileBut.useColors = true;
	nextTileBut.imgs[0] = TextureLoader::rightArrowImg;
	nextTileBut.imgs[1] = TextureLoader::rightArrowImg;
	nextTileBut.colors[0] = WHITE;
	nextTileBut.colors[1] = GREEN;

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

	Button saveButton;
	saveButton.transform.pos = { 50, 200 };
	saveButton.size = { 50, 50 };
	saveButton.transform.disfigure = saveButton.size;
	saveButton.callback = &saveWorld;
	saveButton.imgs[0] = TextureLoader::leftArrowImg;
	saveButton.imgs[1] = TextureLoader::leftArrowImg;
	saveButton.useColors = true;
	saveButton.colors[0] = WHITE;
	saveButton.colors[1] = BLUE;

	Button loadButton;
	loadButton.transform.pos = { 50, 250 };
	loadButton.size = { 50, 50 };
	loadButton.transform.disfigure = loadButton.size;
	loadButton.callback = &loadWorld;
	loadButton.imgs[0] = TextureLoader::rightArrowImg;
	loadButton.imgs[1] = TextureLoader::rightArrowImg;
	loadButton.useColors = true;
	loadButton.colors[0] = WHITE;
	loadButton.colors[1] = GREEN;

	//Button cardTypeBut;
	cardTypeBut.transform.pos = { 450, 25 };
	cardTypeBut.size = { 50, 50 };
	cardTypeBut.transform.disfigure = cardTypeBut.size;
	cardTypeBut.callback = &setCardType;
	cardTypeBut.useColors = true;
	cardTypeBut.imgs[0] = TextureLoader::empty_tile_img;
	cardTypeBut.imgs[1] = TextureLoader::empty_tile_img;
	cardTypeBut.colors[0] = WHITE;
	cardTypeBut.colors[1] = GREEN;

	Button prevCardTypeBut;
	prevCardTypeBut.transform.pos = { 400, 25 };
	prevCardTypeBut.size = { 50, 50 };
	prevCardTypeBut.transform.disfigure = prevCardTypeBut.size;
	prevCardTypeBut.callback = &prevCardType;
	prevCardTypeBut.useColors = true;
	prevCardTypeBut.imgs[0] = TextureLoader::leftArrowImg;
	prevCardTypeBut.imgs[1] = TextureLoader::leftArrowImg;
	prevCardTypeBut.colors[0] = WHITE;
	prevCardTypeBut.colors[1] = GREEN;

	Button nextCardTypeBut;
	nextCardTypeBut.transform.pos = { 500, 25 };
	nextCardTypeBut.size = { 50, 50 };
	nextCardTypeBut.transform.disfigure = nextCardTypeBut.size;
	nextCardTypeBut.callback = &nextCardType;
	nextCardTypeBut.useColors = true;
	nextCardTypeBut.imgs[0] = TextureLoader::rightArrowImg;
	nextCardTypeBut.imgs[1] = TextureLoader::rightArrowImg;
	nextCardTypeBut.colors[0] = WHITE;
	nextCardTypeBut.colors[1] = GREEN;

	


	while (sfw::stepContext())
	{
		sfw::drawCircle(sfw::getMouseX(), sfw::getMouseY(), 3);
		MouseHandler::update();

		if (state == WORLD_STATE)
		{
			player.update();
			avatarModeBut.update();
			genRegBut.update();
			saveButton.update();
			loadButton.update();



			if (usingCard)
			{
				if (deck[deckIdx] != 0)
				{
					vec2 selectPos = { sfw::getMouseX() - 400, sfw::getMouseY() - 300 };
					selectPos = selectPos + player.transform.pos;
					selectPos = { floor((selectPos.x) / 40) * 40,
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


					if (MouseHandler::leftDownStart)
					{

						if (valid && found)
						{
							state = EDIT_STATE;
							//editTileType = 0;
							usingCard = false;
							editTilesNotEntities = true;
							//tileTypeBut.imgs[0] = TextureLoader::empty_tile_img;
							//tileTypeBut.imgs[1] = TextureLoader::empty_tile_img;
						}
					}

					int drawColor = (valid && found) ? GREEN : WHITE;

					Box::draw(player.transform.pos, selectPos, { 40, 40 }, drawColor);
					sfw::drawString(TextureLoader::stringBitmap, newRegionDesc.c_str(), 200, 50, 20, 20);
				}
				else
				{
					cardTypeBut.update();
					nextCardTypeBut.update();
					prevCardTypeBut.update();

					std::string cardDesc;
					switch (newCardType)
					{
					case 0:
						cardDesc = "New card";
						break;
					case 1:
						cardDesc = "Grassland region";
						break;
					case 2:
						cardDesc = "Ocean region";
						break;
					case 3:
						cardDesc = "Forest region";
						break;
					case 4:
						cardDesc = "Mountain region";
						break;
					case 5:
						cardDesc = "Desert region";
						break;
					case 6:
						cardDesc = "Marsh region";
						break;
					default:
						cardDesc = "Dev forgot to add a desc";
						break;
					}

					sfw::drawString(TextureLoader::stringBitmap, "Add a new card", 10, 100, 15, 15);
					sfw::drawString(TextureLoader::stringBitmap, cardDesc.c_str(), 250, 100, 20, 20);
					cardTypeBut.draw();
					nextCardTypeBut.draw();
					prevCardTypeBut.draw();
				}
			}

			avatarModeBut.draw();
			genRegBut.draw();
			saveButton.draw();
			loadButton.draw();
			world.drawWorld(player.transform.pos);
		}
		else if (state == EDIT_STATE)
		{
			if (newReg.tileCounts[0] == 100)
			{
				worldModeBut.update();
			}
			/*grassTileBut.update();
			waterTileBut.update();
			emptyTileBut.update();*/
			prevTileBut.update();
			nextTileBut.update();
			tileTypeBut.update();
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
				if (editTilesNotEntities && newReg.tileCounts[editTileType] > 0)
				{
					++newReg.tileCounts[newReg.getTile((int)regPos.x, (int)regPos.y)];
					newReg.setTile((int)regPos.x, (int)regPos.y, editTileType);
					--newReg.tileCounts[editTileType];
				}
				else if(!editTilesNotEntities)
				{
					newReg.spawners[editSpawner].active = true;
					newReg.spawners[editSpawner].transform.pos = vec2{ regPos.x * 40 + 20, regPos.y * 40 + 20 };
				}
			}


			if (newReg.tileCounts[0] == 100)
			{
				worldModeBut.draw();
			}
			/*grassTileBut.draw();
			waterTileBut.draw();
			emptyTileBut.draw();*/
			//sfw::drawTexture(TileTypes::getImgForType(editTileType), 475, 50, 50, 50);
			sfw::drawString(TextureLoader::stringBitmap, std::to_string(newReg.tileCounts[editTileType]).c_str(), 450, 100, 20, 20);
			tileTypeBut.draw();
			prevTileBut.draw();
			nextTileBut.draw();
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



			player.draw();
			world.drawAvatar(player.transform.pos);

			if (sfw::getKey(KEY_ESCAPE))
			{
				state = WORLD_STATE;
				player.transform.pos = { 20,20 };
			}
		}

		/*std::string decks;
		for (int i = 0; i < deck.size(); ++i)
		{
			decks.append(std::to_string(deck[i]));
			decks.append(",");
		}
		std::cout << decks << std::endl;*/
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
	newReg.tileCounts[0] = -1;
	editTileType = 0;
	world.regs.push_back(newReg);
}

void genRegion(int type)
{
	if (newReg.tileCounts[0] == -1)
	{
		for (int i = 0; i < 3; ++i)
		{
			newReg.spawners[i].active = false;
			newReg.spawners[i].usable = false;
		}

		//int regionType = rand() % 6;
		int regFillType = 0;
		/*
		region types
		0 grassland
		1 ocean
		2 forest
		3 mountain
		4 desert
		5 marsh
		*/

		usingCard = true;
		newReg.tileCounts[0] = 100;

		switch (type)
		{
		case 0:
			newReg.tileCounts[1] = 0;
			newReg.tileCounts[2] = rand() % 10 + 12;
			newReg.tileCounts[3] = rand() % 20;
			newReg.tileCounts[4] = rand() % 5;
			newReg.tileCounts[5] = 0;
			newReg.tileCounts[6] = rand() % 40 + 10;
			newReg.tileCounts[7] = rand() % 5;
			regFillType = 1;
			newRegionDesc = "Grassland region";
			break;
		case 1:
			newReg.tileCounts[1] = rand() % 20 + 5;
			newReg.tileCounts[2] = 0;
			newReg.tileCounts[3] = rand() % 5;
			newReg.tileCounts[4] = rand() % 5;
			newReg.tileCounts[5] = rand() % 10;
			newReg.tileCounts[6] = rand() % 10;
			newReg.tileCounts[7] = rand() % 5;
			regFillType = 2;
			newRegionDesc = "Ocean region";
			break;
		case 2:
			newReg.tileCounts[1] = rand() % 20 + 10;
			newReg.tileCounts[2] = rand() % 10 + 12;
			newReg.tileCounts[3] = 0;
			newReg.tileCounts[4] = rand() % 10 + 5;
			newReg.tileCounts[5] = 0;
			newReg.tileCounts[6] = rand() % 10;
			newReg.tileCounts[7] = rand() % 20;
			regFillType = 3;
			newRegionDesc = "Forest region";
			break;
		case 3:
			newReg.tileCounts[1] = rand() % 10;
			newReg.tileCounts[2] = rand() % 20 + 10;
			newReg.tileCounts[3] = rand() % 15;
			newReg.tileCounts[4] = 0;
			newReg.tileCounts[5] = rand() % 10;
			newReg.tileCounts[6] = rand() % 20 + 10;
			newReg.tileCounts[7] = rand() % 10;
			regFillType = 4;
			newRegionDesc = "Mountain region";
			break;
		case 4:
			newReg.tileCounts[1] = rand() % 5;
			newReg.tileCounts[2] = rand() % 10 + 12;
			newReg.tileCounts[3] = 0;
			newReg.tileCounts[4] = rand() % 5;
			newReg.tileCounts[5] = 0;
			newReg.tileCounts[6] = rand() % 10;
			newReg.tileCounts[7] = rand() % 10;
			regFillType = 5;
			newRegionDesc = "Desert region";
			break;
		case 5:
			newReg.tileCounts[1] = rand() % 20;
			newReg.tileCounts[2] = rand() % 20 + 20;
			newReg.tileCounts[3] = rand() % 20;
			newReg.tileCounts[4] = 0;
			newReg.tileCounts[5] = 0;
			newReg.tileCounts[6] = rand() % 10;
			newReg.tileCounts[7] = 0;
			regFillType = 7;
			newRegionDesc = "Marsh region";
			break;
		default:
			newReg.tileCounts[1] = 100;
			newReg.tileCounts[2] = 0;
			newReg.tileCounts[3] = 0;
			newReg.tileCounts[4] = 0;
			newReg.tileCounts[5] = 0;
			newReg.tileCounts[6] = 0;
			newReg.tileCounts[4] = 0;
			newRegionDesc = "Default region";
			break;
		}

		for (int i = 0; i < 100; ++i)
		{
			newReg.setTile(i, regFillType);
		}
		editTileType = regFillType;
		tileTypeBut.imgs[0] = TileTypes::tileTypes[editTileType].texId;
		tileTypeBut.imgs[1] = TileTypes::tileTypes[editTileType].texId;

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
	editSpawner = 0;
	editTilesNotEntities = false;
	newReg.spawners[0].active = false;
}

void selectSpawnTwo()
{
	editSpawner = 1;
	editTilesNotEntities = false;
	newReg.spawners[1].active = false;
}

void selectSpawnThree()
{
	editSpawner = 2;
	editTilesNotEntities = false;
	newReg.spawners[2].active = false;
}

void previousTileType()
{
	--editTileType;
	editTilesNotEntities = true;
	if (editTileType < 0)
	{
		editTileType = TileTypes::tileTypes.size() - 1;
	}
	tileTypeBut.imgs[0] = TileTypes::tileTypes[editTileType].texId;
	tileTypeBut.imgs[1] = TileTypes::tileTypes[editTileType].texId;
}

void nextTileType()
{
	++editTileType;
	editTilesNotEntities = true;
	if (editTileType == TileTypes::tileTypes.size())
	{
		editTileType = 0;
	}
	tileTypeBut.imgs[0] = TileTypes::tileTypes[editTileType].texId;
	tileTypeBut.imgs[1] = TileTypes::tileTypes[editTileType].texId;
}

void selectTiles()
{
	editTilesNotEntities = true;
}

void saveWorld()
{
	std::ofstream file;
	file.open("world.txt");

	std::string firstline;
	for (int i = 0; i < deck.size(); ++i)
	{
		firstline.append(std::to_string(deck[i]));
		firstline.append(",");
	}
	firstline.append("\n");
	file << firstline;

	for (int i = 0; i < world.regs.size(); ++i)
	{
		std::string line;
		line.append(std::to_string(world.regs[i].transform.pos.x));
		line.append(",");
		line.append(std::to_string(world.regs[i].transform.pos.y));
		line.append(",");
		for (int q = 0; q < 100; ++q)
		{
			line.append(std::to_string(world.regs[i].getTile(q)));
			line.append(",");
		}
		for (int q = 0; q < 3; ++q)
		{
			if (world.regs[i].spawners[q].active)
			{
				line.append(std::to_string(world.regs[i].spawners[q].transform.pos.x));
				line.append(",");
				line.append(std::to_string(world.regs[i].spawners[q].transform.pos.y));
				line.append(",");
				line.append(std::to_string(world.regs[i].spawners[q].cooldown));
				line.append(",");
			}
		}
		if (i < world.regs.size() - 1)
		{
			line.append("\n");
		}
		file << line;
	}

	file.close();
}

void loadWorld()
{
	world.regs.clear();
	deck.clear();

	std::ifstream file;
	file.open("world.txt");

	std::string line;


	std::getline(file, line);

	size_t prevIt = -1;
	size_t it = line.find(',', 0);


	deck.push_back(std::stoi(line.substr(0, it)));
	prevIt = it;
	it = line.find(',', it + 1);
	while (line.find(',', it + 1) != line.npos)
	{
		prevIt = it;
		it = line.find(',', it + 1);
		deck.push_back(std::stoi(line.substr(prevIt + 1, it - prevIt - 1)));
	}


	while (std::getline(file, line))
	{
		prevIt = -1;
		it = line.find(',', 0);

		MapRegion reg;
		reg.transform.pos.x = std::stoi(line.substr(0, it));

		prevIt = it;
		it = line.find(',', it+1);
		reg.transform.pos.y = std::stoi(line.substr(prevIt+1, it - prevIt - 1));

		for (int i = 0; i < 100; ++i)
		{
			prevIt = it;
			it = line.find(',', it + 1);

			reg.setTile(i, std::stoi(line.substr(prevIt + 1, it - prevIt - 1)));
		}

		int spawnIdx = 0;
		while (line.find(',', it + 1) != line.npos)
		{
			prevIt = it;
			it = line.find(',', it + 1);
			reg.spawners[spawnIdx].active = true;
			reg.spawners[spawnIdx].transform.pos.x = std::stoi(line.substr(prevIt + 1, it - prevIt - 1));

			prevIt = it;
			it = line.find(',', it + 1);
			reg.spawners[spawnIdx].transform.pos.y = std::stoi(line.substr(prevIt + 1, it - prevIt - 1));

			prevIt = it;
			it = line.find(',', it + 1);
			reg.spawners[spawnIdx].cooldown = std::stoi(line.substr(prevIt + 1, it - prevIt - 1));

			++spawnIdx;
		}

		world.regs.push_back(reg);
	}

	shuffleDeck();
	file.close();
}





void drawCard()
{
	if (!usingCard)
	{
		++deckIdx;
		if (deckIdx == deck.size())
		{
			shuffleDeck();
			deckIdx = 0;
		}
		usingCard = true;
		if (deck[deckIdx] != 0)
		{
			genRegion(deck[deckIdx] - 1);
		}
		else
		{
			newCardType = 0;
			cardTypeBut.imgs[0] = TileTypes::tileTypes[newCardType].texId;
			cardTypeBut.imgs[1] = TileTypes::tileTypes[newCardType].texId;
		}
	}
}

void nextCardType()
{
	++newCardType;
	if (newCardType > 6)
	{
		newCardType = 0;
	}
	if (newCardType != 6)
	{
		cardTypeBut.imgs[0] = TileTypes::tileTypes[newCardType].texId;
		cardTypeBut.imgs[1] = TileTypes::tileTypes[newCardType].texId;
	}
	else
	{
		cardTypeBut.imgs[0] = TileTypes::tileTypes[7].texId;
		cardTypeBut.imgs[1] = TileTypes::tileTypes[7].texId;
	}
}

void prevCardType()
{
	--newCardType;
	if (newCardType < 0)
	{
		newCardType = 6;
	}
	if (newCardType != 6)
	{
		cardTypeBut.imgs[0] = TileTypes::tileTypes[newCardType].texId;
		cardTypeBut.imgs[1] = TileTypes::tileTypes[newCardType].texId;
	}
	else
	{
		cardTypeBut.imgs[0] = TileTypes::tileTypes[7].texId;
		cardTypeBut.imgs[1] = TileTypes::tileTypes[7].texId;
	}
}

void setCardType()
{
	deck.push_back(newCardType);
	shuffleDeck();
	usingCard = false;
}

void shuffleDeck()
{
	int temp = 0;
	int toSwitch = 0;

	for (int i = 0; i < deck.size(); ++i)
	{
		toSwitch = rand() % deck.size();
		temp = deck[i];
		deck[i] = deck[toSwitch];
		deck[toSwitch] = temp;
	}

	deckIdx = -1;
}
