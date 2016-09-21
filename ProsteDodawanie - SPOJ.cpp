#include <stdio.h>
#include <iostream>

using namespace std;

int main(void)
{
	int t;
	cin >> t;

	int *tablica_wynikow = new int[t];
	for (int i = 0; i < t; i++) tablica_wynikow[i] = 0;

	int ilosc_liczb = 0;

	for (int i = 0; i < t; i++)
	{
		cin >> ilosc_liczb;
		int *liczby = new int[ilosc_liczb];
		for (int j = 0; j < ilosc_liczb; j++) 
		{
			cin >> liczby[j];
			tablica_wynikow[i] += liczby[j];
		}
	}

	for (int i = 0; i < t; i++) cout << tablica_wynikow[i] << "\n";

	delete [] tablica_wynikow;

	return 0;
}