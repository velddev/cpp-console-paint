#include "Console.h"
#include <iostream>

Console::Console()
{
	outStream = GetStdHandle(STD_OUTPUT_HANDLE);
	inStream = GetStdHandle(STD_INPUT_HANDLE);

	SetConsoleMode(inStream, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT);
}

Console::~Console()
{
}

void Console::CursorVisibility(bool value)
{
	CONSOLE_CURSOR_INFO cci;
	cci.bVisible = value;
	cci.dwSize = 25;
	if(!SetConsoleCursorInfo(GetOutHandle(), &cci))
	{
		WriteLine("[WRN] Cannot change the cursor visibility");
	}
}

HANDLE Console::GetOutHandle()
{
	return outStream;
}

HANDLE Console::GetInHandle()
{
	return GetStdHandle(STD_INPUT_HANDLE);
}

void Console::SetCursorPosition(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	if(!SetConsoleCursorPosition(GetOutHandle(), c))
	{
		WriteLine("[WRN] Cannot change the position of the cursor");
	}
}

void Console::SetColor(int id)
{
	SetConsoleTextAttribute(GetOutHandle(), 15);
}

void Console::SetWindowSize(int x, int y)
{
	CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
	if (!GetConsoleScreenBufferInfo(GetOutHandle(), &bufferInfo))
	{
		WriteLine("[WRN] Cannot access buffer");
	}

	SMALL_RECT& winInfo = bufferInfo.srWindow;
	COORD windowSize = { winInfo.Right - winInfo.Left + 1, winInfo.Bottom - winInfo.Top + 1 };

	SMALL_RECT info =
	{
		0,
		0,
		x < windowSize.X ? x - 1 : windowSize.X - 1,
		y < windowSize.Y ? y - 1 : windowSize.Y - 1
	};

	if (!SetConsoleWindowInfo(GetOutHandle(), TRUE, &info))
	{
		WriteLine("[WRN] Cannot set window");
	}
}

void Console::Write(std::string text)
{
	std::cout << text;
}

void Console::WriteLine(std::string text)
{
	std::cout << text << "\n";
}
