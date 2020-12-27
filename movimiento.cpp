#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;
using namespace System;

int main()
{	int x, y, dx ,dy;
	x = 1;
	y = 1;
	dx = 1;
	dy = 1;
	while (1)
	{
		Console::SetCursorPosition(x, y);
		cout << " ";
		if (x + dx >= 80 || x + dx <= 0)
			dx = dx * -1;
		if (y + dy <= 0 || y + dy >= 24)
			dy = dy * -1;
		x = x + dx;
		y = y + dy;
		Console::SetCursorPosition(x, y);
		cout << char(1);
		Sleep(150);
	}
	getch();
	return 0;
}