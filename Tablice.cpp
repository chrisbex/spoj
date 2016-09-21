#include <stdio.h>
#include <iostream>

using namespace std;

int main(void)
{
	int t;
	cin >> t;

	int ilosc_liczb = 0;

	for (int i = 0; i < t; i++)
	{
		cin >> ilosc_liczb;
		int *tablica = new int [ilosc_liczb];
		for (int k = 0; k < ilosc_liczb; k++) cin >> tablica[k];
		for (int h = ilosc_liczb - 1; h >= 0; h--) cout << tablica[h] << " ";
		delete [] tablica;
	}

	return 0;
}