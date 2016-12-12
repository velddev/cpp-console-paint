#pragma once
#include "Vector2.h"

class Brush;

class Renderer
{
public:
	Vector2 position;
	Vector2 size;

	int **map;

	Renderer();
	~Renderer();

	void New(Vector2 size);
	void Draw(Brush* b, Vector2 position);

	bool IsInBounds(Vector2 pos);
};

