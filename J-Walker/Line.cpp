#include "Line.h"


#include "sfwdraw.h"


Line::Line()
{
}


Line::~Line()
{
}


void Line::draw(vec2 playerPos, vec2 start, vec2 end)
{
	vec2 startOffset;
	startOffset.x = playerPos.x - start.x;
	startOffset.y = playerPos.y - start.y;
	vec2 endOffset;
	endOffset.x = playerPos.x - end.x;
	endOffset.y = playerPos.y - end.y;

	//sfw::drawLine(lineStart.x, lineStart.y, lineEnd.x, lineEnd.y);
	sfw::drawLine(400 - startOffset.x,
		300 - startOffset.y,
		400 - endOffset.x,
		300 - endOffset.y);
}

void Line::draw(vec2 playerPos, vec2 start, vec2 end, size_t color)
{
	vec2 startOffset;
	startOffset.x = playerPos.x - start.x;
	startOffset.y = playerPos.y - start.y;
	vec2 endOffset;
	endOffset.x = playerPos.x - end.x;
	endOffset.y = playerPos.y - end.y;

	//sfw::drawLine(lineStart.x, lineStart.y, lineEnd.x, lineEnd.y);
	sfw::drawLine(400 - startOffset.x,
		300 - startOffset.y,
		400 - endOffset.x,
		300 - endOffset.y, color);
}
