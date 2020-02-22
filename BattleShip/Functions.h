#pragma once
#include<iostream>
#include<math.h>
#include<algorithm>
#include "Ship.cpp"
using namespace std;

int GetRandomNumber()
{
	return rand() % 100 + 0;				//un numar random pentru atacul navei
}

void DisplayTopLine()
{
	cout << endl;
	for (int i = 1; i <= 21; i++)
	{
		cout << " -";
	}
	cout << endl;
}

void DisplayBottomLine()
{
	cout << endl;
	for (int i = 1; i <= 21; i++)
	{
		cout << " -";
	}
	cout << endl;
}

void DisplayShips(Ship first, Ship second)
{
	int **matrix1, **matrix2;
	matrix1 = first.GetMatrix();
	matrix2 = second.GetMatrix();
	
	DisplayTopLine();					//afiseaza linia de sus a tabloului

	for (int i = 0; i < 10; i++)						//afiseaza continutul tabloului
	{
		for (int j = 0; j <= 20; j++)
		{
			if (j < 10) 
			{
				if (matrix1[i][j] == 1) cout << " *";
				else cout << "  ";
			}
			else if (j > 10)
			{
				if (matrix2[i][j - 11] == 1) cout << " *";
				else cout << "  ";
			}
			else cout << " |";
			
		}
		if (i != 9) 
		{ 
			cout << endl;
		}
	}
	
	DisplayBottomLine();						//afiseaza linia de jos a tabloului
}

void ReadAndUpdate(int noBoat, Ship& boat)
{
	cout << "CPU " << noBoat << " : " << endl;
	int aux = 1;
	cout << "Introduceti '0' pentru a termina de introdus barcile" << endl;
	
	while (aux)
	{
		cout << "Pozitia pentru barca este: ";
		cin >> aux;
		if (aux == 0) 
		{
			cout << "Ati terminat de introdus barci" << endl << endl << endl;
			return;
		}
		else if (aux < 0 || aux > 99)
		{
			cout << "Numar gresit!" << endl;
		}
		else
		{
			boat.UpdateShip(aux);
		}
	}
}

void Play(Ship& first, Ship& second)
{
	cout << endl << endl << endl << "Tablou inital:" << endl << endl;
	DisplayShips(first, second);
	cout << endl << endl;

	while (1 == 1)			//loop infinit cu iesire doar la terminarea jocului
	{
		if (first.NoShips())				//daca 1 nu mai are nave, a castigat 2 si stop joc
		{
			cout << "CPU 2 a castigat, CPU 1 nu mai are nave" << endl;
			return;
		}
		if (second.NoShips())			   //daca 2 nu mai are nave,  a castigat 1 si stop joc
		{
			cout << "CPU 1 a castigat, CPU 2 nu mai are nave" << endl;
			return;
		}
		int aux = GetRandomNumber();
		cout << "CPU 1 a ales: " << aux << endl;
		if (second.VerifyShip(aux))					//verifica daca a lovit o nava sau nu
		{
			cout << "A lovit o barca!" << endl;
			second.DestroyShip(aux);
		}
		else cout << "A dat pe langa!" << endl;
		
		aux = GetRandomNumber();
		cout << "CPU 2 a ales: " << aux << endl;
		if (first.VerifyShip(aux))					//verifica daca a lovit o nava sau nu
		{
			cout << "A lovit o barca!" << endl;
			first.DestroyShip(aux);
		}
		else cout << "A dat pe langa!" << endl;

		DisplayShips(first,second);
	}

}
