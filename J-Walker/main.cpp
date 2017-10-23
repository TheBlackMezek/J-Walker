
#include <iostream>
#include <time.h>

#include "sfwdraw.h"
#include "MathLib\Transform.h"

#include "Player.h"
#include "Box.h"
#include "Circle.h"



int main()
{
	srand(time(NULL));



	sfw::initContext(800, 600, "J-Walker");

	sfw::setBackgroundColor(BLACK);




	Player player;
	vec2 boxpos = { 100, 100 };
	vec2 boxsize = { 20, 20 };
	vec2 circlepos = { 200, 200 };
	float circleradius = 40;




	while (sfw::stepContext())
	{
		player.update();

		player.draw();
		Box::draw(player.transform.pos, boxpos, boxsize);
		Circle::draw(player.transform.pos, circlepos, circleradius);
	}



	return 0;
}