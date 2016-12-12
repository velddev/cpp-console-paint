#include <iostream>
#include <stdlib.h>
#include <windows.h>

#include "Console.h"
#include "BrushBlock.h"

using namespace std;

int currentColor = 15;

bool holdingColor = false;

void DrawUI(Console* console)
{
	console->SetCursorPosition(0, 1);

	console->SetColor(15);

	console->WriteLine("================================================================================================================================================================");

	console->SetCursorPosition(0, 0);
	console->SetColor(currentColor);
	console->Write("COLOR");

}

void TickInput(Console* console)
{
	INPUT_RECORD InputRecord;

	DWORD Events;
	COORD coord;

	ReadConsoleInput(console->GetInHandle(), &InputRecord, 1, &Events);

	if(InputRecord.EventType == INPUT_KEYBOARD)
	{
		if(InputRecord.Event.KeyEvent.uChar.AsciiChar == 'c')
		{
			currentColor++;
			if(currentColor > 15)
			{
				currentColor = 1;
			}
		}
		else
		{
		}
	}
	else if (InputRecord.EventType == MOUSE_EVENT)
	{
		switch (InputRecord.Event.MouseEvent.dwButtonState)
		{
		case MOUSEEVENTF_LEFTDOWN:
		{
			coord.X = InputRecord.Event.MouseEvent.dwMousePosition.X;
			coord.Y = InputRecord.Event.MouseEvent.dwMousePosition.Y;
			console->SetCursorPosition(coord.X - 3 / 2, coord.Y - 3 / 2);
			console->SetColor(0);

			BrushBlock b = BrushBlock();
			b.SetSize(3);
			BrushPacket p = b.DoPaint();

			for(int i = 0; i < 3; i++)
			{
				for(int j = 0; j < 3; j++)
				{
					console->Write(std::to_string(p.packet[i][j]));
				}
				console->SetCursorPosition(coord.X - 3 / 2 + i, coord.Y - 3 / 2);
			}

		} break;

		case MOUSEEVENTF_MOVE:
		{
			coord.X = InputRecord.Event.MouseEvent.dwMousePosition.X;
			coord.Y = InputRecord.Event.MouseEvent.dwMousePosition.Y;
			console->SetCursorPosition(coord.X, coord.Y);
			console->SetColor(currentColor);
			console->Write("x");
		} break;
		}
	}
	FlushConsoleInputBuffer(console->GetInHandle());
}

int main()
{
	Console* c = new Console();
	c->CursorVisibility(false);

	while (true)
	{
		TickInput(c);
		DrawUI(c);
	}	
	return 0;
}

