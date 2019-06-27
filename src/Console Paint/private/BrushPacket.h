#pragma once
#include "Vector2.h"

class BrushPacket
{
public:
	Vector2 position;
	Vector2 size;

	Vector2 posInPacket;

	char **packet;
	int **color;

	BrushPacket();
	BrushPacket(int size);
	~BrushPacket();

	void Add(char c, int color);
	void NewLine();
};

