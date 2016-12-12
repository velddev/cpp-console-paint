#include "BrushBlock.h"

BrushBlock::BrushBlock()
{
}


BrushBlock::~BrushBlock()
{
	Brush::~Brush();
}

BrushPacket BrushBlock::DoPaint()
{
	BrushPacket p = BrushPacket(size);

	for(int x = 0; x < size; x++)
	{
		for(int y = 0; y < size; y++)
		{
			p.Add('X', 15);
		}
		p.NewLine();
	}

	return p;
}
