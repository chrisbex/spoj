#include <stdio.h>
#include <iostream>

using namespace std;

int main(void)
{
	int t; 
	cin >> t;

	long a;

	for (int i = 0; i < t; i++)
	{
		cin >> a;
		for (int k = a-1; k > 0; k--) a *= k;
		cout << (a%100)/10 << " " << a%10 << "\n";
	}

	return 0;
}