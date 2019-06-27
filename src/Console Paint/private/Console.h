#pragma once
#include <string>
#include <windows.h>

class Console
{
public:
	Console();
	~Console();

	void CursorVisibility(bool value);
	
	HANDLE GetOutHandle();
	HANDLE GetInHandle();

	void SetCursorPosition(int x, int y);
	void SetColor(int id);
	void SetWindowSize(int x, int y);

	void Write(std::string text);
	void WriteLine(std::string text);

private:
	HANDLE inStream;
	HANDLE outStream;
};

