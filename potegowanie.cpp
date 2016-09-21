#include <iostream>

using namespace std;

int main(void)
{
	int t = 0; 							//liczba testow
	cin >> t;

	int v1 = 0, v2 = 0; 			// predkosci

	for (int i = 0; i < t; i ++)
	{
		cin >> v1 >> v2;
		cout << 2 * (v1 * v2) / (v1 + v2);
	}

	return 0;
}
