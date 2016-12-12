#pragma once
#include "BrushPacket.h"

class Brush
{
public:
	char symbol;
	int size;

	Brush();
	Brush(char symbol, int size);

	virtual ~Brush();

	virtual BrushPacket DoPaint() = 0;

	void SetSize(int size);
};

