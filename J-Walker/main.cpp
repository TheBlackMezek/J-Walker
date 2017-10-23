
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



int main()
{
	srand(time(NULL));



	sfw::initContext(800, 600, "J-Walker");

	sfw::setBackgroundColor(BLACK);

	TextureLoader::init();




	Player player;
	World world;

	Button bb;
	bb.transform.pos = { 250, 250 };
	bb.imgs[0] = TextureLoader::back_button_1;
	bb.imgs[1] = TextureLoader::back_button_2;

	


	while (sfw::stepContext())
	{
		player.update();
		bb.update();



		player.draw();
		sfw::drawCircle(sfw::getMouseX(), sfw::getMouseY(), 3);

		//world.drawAvatar(player.transform.pos);
		world.drawWorld(player.transform.pos);
		//world.drawEdit({ 0,0 });

		bb.draw();
	}



	return 0;
}