#include <iostream>

using namespace std;

int main(void)
{
	int t = 0;
	cin >> t;

	long long int a = 0, b = 0;

	for (int i = 0; i < t; i++)
	{
		cin >> a >> b;
		if (a == 1 && b != 0) cout << "TAK\n";
		else if (a == 1 && b == 0) cout << "NIE\n";
		else if (a > 1 && b > 0)
		{
			if (b % a - 1) cout << "TAK\n";
			else cout << "NIE\n";
		}
	}

	return 0;
}