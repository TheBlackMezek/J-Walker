
#include <iostream>
#include <time.h>

#include "sfwdraw.h"
#include "MathLib\Transform.h"

#include "Player.h"
#include "Box.h"
#include "Circle.h"
#include "MapRegion.h"



int main()
{
	srand(time(NULL));



	sfw::initContext(800, 600, "J-Walker");

	sfw::setBackgroundColor(BLACK);




	Player player;
	MapRegion reg;




	while (sfw::stepContext())
	{
		player.update();

		player.draw();
		reg.draw();
	}



	return 0;
}