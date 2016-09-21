#include <iostream>

using namespace std;

float wartosc_bezwzgledna(float b)
{
	if (b < 0) return -b;
	else return b;
}

float policz_srednia(int *tab, int wielkosc_tablicy)
{
	int suma = 0; 
	for (int i = 0; i < wielkosc_tablicy; i++)
	{ 	
		suma += tab[i];
	}
	float sr = (float)suma / (float)wielkosc_tablicy;
	return sr;
}

int nearest_number(int *tab, int wielkosc_tablicy, float srednia)
{
	float temp = 20000; int element = 0;
	for (int i = 0; i < wielkosc_tablicy; i++)
	{
		if (wartosc_bezwzgledna((float)tab[i] - srednia) < temp)
		{
			temp = wartosc_bezwzgledna(tab[i] - srednia);
			element  = i;
		} 
	}
	return element;
}

int main(void)
{
	int t;
	cin >> t;

	int *tab = new int[100];
	unsigned int ilosc_liczb = 0;

	for (int i = 0; i < t; i++)
	{
		cin >> ilosc_liczb;
		for (int j = 0; j < ilosc_liczb; j++) cin >> tab[j];
		float srednia = policz_srednia(tab, ilosc_liczb);
		int n = nearest_number(tab, ilosc_liczb, srednia);
		cout << tab[n] << endl;
	}

	return 0;
}