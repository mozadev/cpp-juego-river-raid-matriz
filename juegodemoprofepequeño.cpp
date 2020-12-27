#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#define N 10
#define M 10
using namespace std;
using namespace System;
int Mapa1[N][M] = {
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 1, 0, 2, 0, 0, 0, 1 },
	{ 1, 0, 0, 1, 0, 0, 0, 0, 0, 1 },//0 = espacio vacio; 1=pared;  2= comida; 3 = salida del juego o puerta
	{ 1, 0, 0, 1, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 1, 0, 0, 2, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 3, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
};
int Mapa2[N][M] = {
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 1, 0, 2, 0, 0, 0, 1 },
	{ 1, 0, 0, 1, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 1, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 1, 1, 1, 2, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 3, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
};
void AsignarMatriz(int *Nivel, int **Matriz)
{
	if (*Nivel == 1)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				Matriz[i][j] = Mapa1[i][j];
	if (*Nivel == 2)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				Matriz[i][j] = Mapa2[i][j];
	//if (*Nivel == 2)
}
void MuestraMapa(int **Matriz)
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			Console::SetCursorPosition(j, i);
			Console::BackgroundColor = ConsoleColor::Black;
			if (Matriz[i][j] == 0)
				cout << " ";
			if (Matriz[i][j] == 1)
			{
				Console::ForegroundColor = ConsoleColor::Red;
				cout << char(219);
			}
			if (Matriz[i][j] == 2)
			{
				Console::ForegroundColor = ConsoleColor::Blue;
				cout << "*";
			}

			if (Matriz[i][j] == 3)
			{
				Console::ForegroundColor = ConsoleColor::Magenta;
				cout << char(219);
			}

		}
}

void Juego(int x, int y,int **Matriz)
{
	
	char Tecla;
	Console::SetCursorPosition(x, y);
	Console::ForegroundColor = ConsoleColor::White;
	Console::BackgroundColor = ConsoleColor::Black;
	cout << "+";
	bool dir = true;
	int i = 1;
	int k = 1;


	while (1)
	{

		while (!kbhit())//esto prueba que la tecla no esta presionada.
		{
			Console::CursorVisible = false;
			Console::SetCursorPosition(6, i);
			cout << char(215);
			Sleep(300);
			Console::SetCursorPosition(6, i);
			cout << " ";
			if (dir == true)
				i++;
			else
				i--;
			if (i == 8)
				dir = false;
			if (i == 1)
				dir = true;

		}


		Tecla = _getch();
		Console::SetCursorPosition(x, y);
		cout << " ";
		if (Tecla == 72) //arriba
		{
			y--;
			if (Matriz[y][x] == 1)
				y++;
		}
		if (Tecla == 80) //abajo
		{
			y++;
			if (Matriz[y][x] == 1)
				y--;
		}
		if (Tecla == 75) // izquierda
		{
			x--;
			if (Matriz[y][x] == 1)
				x++;
		}
		if (Tecla == 77) //derecha
		{
			x++;
			if (Matriz[y][x] == 1)
				x--;
		}
		if (x == 8 && y == 8)
			break;
		Console::SetCursorPosition(x, y);
		cout << "+";
	}
}
int main()
{
	int x;
	cout << "ingrese posicion x del auto"; cin >> x;
	int y;
	cout << "ingrese posicion y del auto"; cin >> y;
	int **Matriz;
	int Nivel;
	Matriz = new int *[N];
	for (int i = 0; i < N; i++)
		Matriz[i] = new int[M];

	Nivel = 1;
	AsignarMatriz(&Nivel, Matriz);
	MuestraMapa(Matriz);
	Juego(x,y,Matriz);

	
	_getch;
}