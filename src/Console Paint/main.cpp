#include <iostream>
#include <stdlib.h>
#include <windows.h>

#include "Console.h"
#include "BrushBlock.h"
#include "Renderer.h"

using namespace std;

int currentColor = 15;
int brushSize = 2;

bool holdingColor = false;

Renderer renderer;

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
	// Input event record
	INPUT_RECORD InputRecord;

	// Declaring windows api variables
	DWORD Events;
	COORD coord;

	// Get record from message queue
	ReadConsoleInput(console->GetInHandle(), &InputRecord, 1, &Events);

	// Check if current event is a keyboard input event.
	if(InputRecord.EventType == INPUT_KEYBOARD)
	{
		if (InputRecord.Event.KeyEvent.uChar.AsciiChar == 'c')
		{
			currentColor++;
			if (currentColor > 15)
			{
				currentColor = 1;
			}
		}
		else
		{
		}
	}

	// Otherwise check if it's a mouse event
	else if (InputRecord.EventType == MOUSE_EVENT)
	{
		// Drawing code
		switch (InputRecord.Event.MouseEvent.dwButtonState)
		{
		// RIGHT MOUSE DOWN. Windows api please...
		case MOUSEEVENTF_LEFTDOWN:
		{
			coord.X = InputRecord.Event.MouseEvent.dwMousePosition.X;
			coord.Y = InputRecord.Event.MouseEvent.dwMousePosition.Y;

			BrushBlock* b = new BrushBlock();
			b->size = 3;
			b->symbol = 'x';

			renderer.Draw(b, Vector2(coord.X, coord.Y), console);
		} break;

		// HAHA ACTUALLY THIS IS LEFT MOUSE DOWN!
		case MOUSEEVENTF_MOVE:
		{
			coord.X = InputRecord.Event.MouseEvent.dwMousePosition.X;
			coord.Y = InputRecord.Event.MouseEvent.dwMousePosition.Y;

			BrushBlock* b = new BrushBlock();
			b->size = 3;
			b->symbol = ' ';

			renderer.Draw(b, Vector2(coord.X, coord.Y), console);
		} break;
		}
	}

	// Write the event data to the buffer.
	FlushConsoleInputBuffer(console->GetInHandle());
}

int main()
{
	// Define a new console window.
	Console* c = new Console();

	// Create the renderer
	renderer = Renderer();
	
	// Declare the size and the position on the screen
	renderer.New(Vector2(37, 159));
	renderer.position = Vector2(0, 2);
	
	// Console stuff, cursor causes flickering during rendering.
	c->SetWindowSize(160, 40);
	c->SetColor(15);
	c->CursorVisibility(false);

	renderer.Render(c);

	// Event message queue
	while (true)
	{
		// Gets console event messages and handles them
		TickInput(c);

		// Draws UI over renderer
		DrawUI(c);
	}	
	return 0;
}

/*
 * 			
 */

/*
 * 			
 */

/*
 * 		
 */