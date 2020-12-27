#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;
using namespace System;
void DibujarVida(int vida){	
	Console::SetCursorPosition(70, 0);
	cout << "          ";
	Console::SetCursorPosition(70, 0);
	cout << "Vidas: ";
	for (int i = 0; i < vida; i++)
	{
		cout << char(3);
	}
}
void Perdiste(){
	Console::Clear();
	Console::SetCursorPosition(35, 12);
	cout << "PERDISTE";
	getch();
}
int main()
{
	int x, y;
	int dx, dy,vida;
	vida = 3;
	x = 40; y = 12;
	dx = dy = 0;

	int xE, yE,dyE;
	xE = 10; yE = 10; dyE = 1;
	char tecla;
	DibujarVida(vida);
	while (1){
		dx = dy = 0;
		Console::SetCursorPosition(xE, yE);
		cout << " ";
		if (kbhit())
		{
			Console::SetCursorPosition(x, y);
			cout << " ";
			tecla = getch();
			switch (tecla)
			{
			case 'W':
				dy = -1;
				break;
			case 'S':
				dy = 1;
				break;
			case 'D':
				dx = 1;
				break;
			case 'A':
				dx = -1;
				break;
			}
			x = x + dx;
			y = y + dy;
		}
		
		if (x == xE && y == yE)
		{
			vida--;
			if (vida == 0)
				Perdiste();
			DibujarVida(vida);
			x = 40; y = 12;
		}

		Console::SetCursorPosition(x, y);
		cout << "*";

		
		if (yE + dyE >= 24 || yE + dyE <=0)
			dyE = dyE*-1;
		yE += dyE;

		Console::SetCursorPosition(xE, yE);
		cout << char(219);
		Sleep(100);
	}
	getch();
	return 0;
}