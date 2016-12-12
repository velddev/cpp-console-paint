#include "Brush.h"

Brush::Brush()
{
}

Brush::Brush(char symbol, int size)
	: symbol(symbol), size(size)
{

}

Brush::~Brush()
{
}

void Brush::SetSize(int size)
{
	this->size = size;
}
