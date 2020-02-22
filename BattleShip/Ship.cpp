#pragma once
#include<iostream>
using namespace std;


class Ship
{
private:
	int** matrix;

public:

	Ship(int var = 0)
	{
		matrix = new int*[10];
		for (int i = 0; i <= 9; i++)
		{
			matrix[i] = new int[10];
		}

		for (int i = 0; i <= 9; i++)
		{
			for (int j = 0; j <= 9; j++)
			{
				matrix[i][j] = var;
			}
		}
	}

	void UpdateShip(int var)
	{
		int dec = var / 10, unit = var % 10;
		matrix[dec][unit] = 1;
	}

	void DestroyShip(int var)
	{
		int dec = var / 10, unit = var % 10;
		matrix[dec][unit] = 0;
	}

	int** GetMatrix()
	{
		return matrix;
	}

	bool VerifyShip(int var)
	{
		int dec = var / 10, unit = var % 10;
		if (matrix[dec][unit]) return true;
		return false;
	}

	void DisplayMatrix()
	{
		for (int i = 0; i <= 9; i++)
		{
			for (int j = 0; j <= 9; j++)
			{
				cout << matrix[i][j];
			}
			cout << endl;
		}
	}

	bool NoShips()
	{
		for (int i = 0; i <= 9; i++)
		{
			for (int j = 0; j <= 9; j++)
			{
				if (matrix[i][j]) return false;
			}
		}
		return true;
	}
};