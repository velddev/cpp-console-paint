#include "Vector2.h"

Vector2::Vector2()
{
	x = 0;
	y = 0;
}

Vector2::Vector2(int x, int y) 
	: x(x), y(y)
{
	
}

Vector2::~Vector2()
{
}

COORD Vector2::ToCoords()
{
	COORD c;
	c.X = x;
	c.Y = y;
	return c;
}
