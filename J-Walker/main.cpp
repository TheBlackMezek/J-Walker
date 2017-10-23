
#include <iostream>
#include <time.h>

#include "sfwdraw.h"
#include "MathLib\Transform.h"

#include "Player.h"
#include "Box.h"
#include "Circle.h"
#include "World.h"



int main()
{
	srand(time(NULL));



	sfw::initContext(800, 600, "J-Walker");

	sfw::setBackgroundColor(BLACK);




	Player player;
	World world;




	while (sfw::stepContext())
	{
		player.update();

		player.draw();
		//world.drawAvatar(player.transform.pos);
		world.drawWorld(player.transform.pos);
		//world.drawEdit({ 0,0 });
	}



	return 0;
}