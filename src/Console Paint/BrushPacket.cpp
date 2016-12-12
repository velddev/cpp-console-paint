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
	}
	color = new int*[size];
	for (int i = 0; i < size; i++)
	{
		color[i] = new int[size];
	}
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
