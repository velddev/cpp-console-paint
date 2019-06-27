#include "Brush.h"

Brush::Brush()
	: symbol(' '), size(size)
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

void Brush::SetSymbol(char newSymbol)
{
	this->symbol = newSymbol;
}