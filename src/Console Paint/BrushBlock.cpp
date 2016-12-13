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

	for(int x = 0; x < p.size.x; x++)
	{
		for(int y = 0; y < p.size.y; y++)
		{
			p.Add(symbol, 15);
		}
		p.NewLine();
	}

	return p;
}
