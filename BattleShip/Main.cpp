#include "Functions.h"

using namespace std;

int main()
{
	Ship first, second;
	int maxMoves;
	cout << "Introduceti numarul maxim de mutari, pentru a nu se rula prea mult timp: ";
	cin >> maxMoves;
	cout << endl;
	ReadAndUpdate(1, first);
	ReadAndUpdate(2, second);
	Play(first,second, maxMoves);
}

