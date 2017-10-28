#pragma once
class MouseHandler
{
public:
	MouseHandler();
	~MouseHandler();

	static bool leftDown;
	static bool leftDownStart;

	static void init();
	static void update();
};

