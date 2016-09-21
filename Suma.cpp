#include <stdio.h>
#include <iostream>

using namespace std;

int main(void)
{	
	short int a;
	int suma = 0;

	while (cin >> a) 
	{
		suma += a;
		cout << suma << "\n";
	}

	return 0;
}