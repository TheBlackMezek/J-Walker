#include "Button.h"


#include "sfwdraw.h"

#include "MathLib\Mat3.h"



Button::Button()
{
	callback = nullptr;

	transform.pos = { 0,0 };
	transform.disfigure = { 100, 100 };
	size = { 50,50 };

	imgs[0] = 0;
	imgs[1] = 0;

	mouseOver = false;
}


Button::~Button()
{
}


void Button::update()
{
	vec2 mouse = { sfw::getMouseX(), sfw::getMouseY() };

	if (mouse.x >= transform.pos.x && mouse.x < transform.pos.x + size.x &&
		mouse.y >= transform.pos.y && mouse.y < transform.pos.y + size.y)
	{
		mouseOver = true;
	}
	else
	{
		mouseOver = false;
	}
}

void Button::draw()
{
	Mat3 m = transform.getLocalTransform();
	//m[6] += 25;
	//m[7] += 25;
	
	m = m + translation({ 50, 50 });

	sfw::drawTextureMatrix3(imgs[mouseOver], 0U, WHITE, m.m);
	//sfw::drawTexture(imgs[mouseOver], transform.pos.x, transform.pos.y, size.x, size.y);
}
