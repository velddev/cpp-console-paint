#include "Renderer.h"
#include "Brush.h"
#include "Console.h"


Renderer::Renderer()
{
}


Renderer::~Renderer()
{
}

void Renderer::New(const Vector2 size)
{
	map = new char*[size.x];
	for(int i = 0; i < size.x; i++)
	{
		map[i] = new char[size.y];
		for(int j = 0; j < size.y; j++)
		{
			map[i][j] = '.';
		}
	}
	this->size = size;
}

void Renderer::Draw(Brush* b, Vector2 pos, Console* console)
{
	if (IsInBounds(pos))
	{
		BrushPacket p = b->DoPaint();
		for (int x = pos.x; x <pos.x + p.size.x; x++)
		{
			for (int y = pos.y; y < pos.y + p.size.y; y++)
			{
				map[y - position.y][x - position.x] = p.packet[y - pos.y][x - pos.x];
			}
		}

		std::string output = "";

		for (int x = pos.x; x < pos.x + p.size.x; x++)
		{
			for (int y = pos.y; y < pos.y + p.size.y; y++)
			{
				output += map[y][x];
			}
			console->SetCursorPosition(x, pos.y);
			console->Write(output);
			output = "";
		}
	}
}

void Renderer::Render(Console* c)
{
	Vector2 currentPos = position;

	std::string output = "";

	for (int x = 0; x < size.x; x++)
	{
		for (int y = 0; y < size.y; y++)
		{
			output += map[x][y];
		}
		output += "\n";
	}

	c->SetCursorPosition(position.x, position.y);
	c->Write(output);
}

bool Renderer::IsInBounds(Vector2 pos)
{
	int xMAX = position.x + size.x;
	int xMIN = position.x;
	int yMAX = position.y + size.y;
	int yMIN = position.y;

	return (xMAX > pos.y && xMIN <= pos.y && yMAX > pos.x && yMIN <= pos.x);
}