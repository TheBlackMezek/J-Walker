#include "MouseHandler.h"


#include "sfwdraw.h"




bool MouseHandler::leftDown;
bool MouseHandler::leftDownStart;





MouseHandler::MouseHandler()
{
}


MouseHandler::~MouseHandler()
{
}


void MouseHandler::init()
{
	leftDown = false;
	leftDownStart = false;
}

void MouseHandler::update()
{
	if (sfw::getMouseButton(0))
	{
		if (!leftDown)
		{
			leftDownStart = true;
		}
		else
		{
			leftDownStart = false;
		}
		leftDown = true;
	}
	else
	{
		leftDown = false;
	}
}
