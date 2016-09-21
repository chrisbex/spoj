#include <iostream>

using namespace std;

int main(void)
{
	int t;
	cin >> t;

	int tablica[100];
	int ilosc_liczb, pierwszy_element;

	for (int i = 0; i < t; i++)
	{
		cin >> ilosc_liczb >> pierwszy_element;
		for (int j = 0; j < ilosc_liczb - 1; j++) cin >> tablica[j];
		tablica[ilosc_liczb - 1] = pierwszy_element;
		for (int k = 0; k < ilosc_liczb; k++) cout << tablica[k];
	}

	return 0;
}