#pragma once
#include <windows.h>

class Vector2
{
public:
	int x;
	int y;

	Vector2();
	Vector2(int x, int y);

	~Vector2();

	COORD ToCoords();
};

