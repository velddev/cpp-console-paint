#pragma once
#include "Vector2.h"
#include "Console.h"

class Brush;

class Renderer
{
public:
	Vector2 position;
	Vector2 size;

	char **map;

	Renderer();
	~Renderer();

	void New(Vector2 size);
	void Draw(Brush* b, Vector2 position, Console* console);
	void Render(Console* c);
	bool IsInBounds(Vector2 pos);
};

