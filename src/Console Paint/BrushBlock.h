#pragma once
#include "Brush.h"
#include "BrushPacket.h"

class BrushBlock : public Brush
{
public:
	BrushBlock();
	~BrushBlock();

	BrushPacket DoPaint() override;
};

