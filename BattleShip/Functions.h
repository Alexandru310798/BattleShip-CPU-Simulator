#pragma once
#include<iostream>
#include<math.h>
#include<algorithm>
#include "Ship.cpp"
#include<list>
using namespace std;

int GetRandomNumber()
{
	return rand() % 100 + 0;				//un numar generat random folosit pentru atacul unei nave, cat si pentru generarea lor, ca si pozitii
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

bool AlreadyExists(list<int> L, int value)
{
	if (find(L.begin(), L.end(), value) != L.end())
	{
		return true;
	}
	return false;
}

void ShowListOfBoats(list<int> L)
{
	cout << endl << "Lista barcilor generate pe pozitiile: ";
	list<int>::iterator it;
	for (it = L.begin(); it != L.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void ReadAndUpdate(int noBoat, Ship& boat)
{
	cout << "CPU " << noBoat << " : " << endl;
	int numberBoats = 1;
	cout << "Numarul de barci pe care il doriti: ";
	cin >> numberBoats;
	list<int> listBoats;
	while (numberBoats)
	{
		int aux = GetRandomNumber();
		while (AlreadyExists(listBoats, aux))		// cat timp deja exista o barca pe acea pozitie, cautam o alta pozitie libera
		{
			aux = GetRandomNumber();
		}
		listBoats.push_back(aux);
		boat.UpdateShip(aux);
		numberBoats--;
	}
	
	ShowListOfBoats(listBoats);
}


void Play(Ship& first, Ship& second, int maxMoves)
{
	cout << endl << endl << endl << "Tablou inital:" << endl << endl;
	DisplayShips(first, second);
	cout << endl << endl;
	int iterations = 0;
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

		iterations++;
		if (iterations == maxMoves)
		{
			cout << "S-au facut 100 de miscari, nimeni nu a castigat." << endl << "Rezultatul este unul de egalitate";
			return;
		}
	}

}
