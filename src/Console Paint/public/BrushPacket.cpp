#include "BrushPacket.h"

BrushPacket::BrushPacket()
	: packet(nullptr), color(nullptr)
{
}
BrushPacket::BrushPacket(int size)
{
	packet = new char*[size];
	for(int i = 0 ; i < size; i ++)
	{
		packet[i] = new char[size];
		for (int j = 0; j < size; j++)
		{
			packet[i][j] = 'x';
		}
	}
	color = new int*[size];
	for (int i = 0; i < size; i++)
	{
		color[i] = new int[size];
		for(int j = 0; j < size; j++)
		{
			color[i][j] = -1;
		}
	}
	this->size = Vector2(size, size);
}

BrushPacket::~BrushPacket()
{
}

void BrushPacket::Add(char brush, int col)
{
	packet[posInPacket.x][posInPacket.y] = brush;
	color[posInPacket.x][posInPacket.y] = col;

	posInPacket.x++;
}

void BrushPacket::NewLine()
{
	posInPacket.y++;
	posInPacket.x = 0;
}
