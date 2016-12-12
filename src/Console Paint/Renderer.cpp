#include "Renderer.h"
#include "Brush.h"


Renderer::Renderer()
{
}


Renderer::~Renderer()
{
}

void Renderer::New(const Vector2 size)
{
	map = new int*[size.x];
	for(int i = 0; i < size.x; i++)
	{
		map[i] = new int[size.y];
	}
}

void Renderer::Draw(Brush* b, Vector2 pos)
{
	if(IsInBounds(pos))
	{
		b->DoPaint();
	}
}

bool Renderer::IsInBounds(Vector2 pos)
{
	return (position.x + size.x < pos.x && position.x >= pos.x && position.y + size.y < pos.y && position.y >= pos.y);
}