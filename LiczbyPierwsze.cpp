#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

int check_prime(int x)
{
  	if (x == 1) return 0;
  	long r = sqrt(x);
  	long i = 2;
  	while (i <= r) if(!(x % i++)) return 0;
  	return 1;
}

int main(void)
{
	int t;
	cin >> t;

	long a;

	for (int i = 0; i < t; i++)
	{
		cin >> a;
		int temp = check_prime(a);
		if (temp == 1) cout << "TAK\n";
		else cout << "NIE\n";
	}

	system("pause");
	return 0;
}
