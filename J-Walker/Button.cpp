#include "Button.h"


#include "sfwdraw.h"

#include "MathLib\Mat3.h"



Button::Button()
{
	callback = nullptr;

	transform.pos = { 0,0 };
	size = { 50,50 };
	transform.disfigure = size;

	imgs[0] = 0;
	imgs[1] = 0;

	mouseOver = false;
	useColors = false;
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
		if (sfw::getMouseButton(0))
		{
			callback();
		}
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
	
	m = translation({ size.x / 2, size.y / 2 }) * m;

	int color = WHITE;
	if (useColors)
	{
		color = colors[mouseOver];
	}

	sfw::drawTextureMatrix3(imgs[mouseOver], 0U, color, m.m);
	//sfw::drawTexture(imgs[mouseOver], transform.pos.x, transform.pos.y, size.x, size.y);
}
