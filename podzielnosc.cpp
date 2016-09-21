#include <iostream>

using namespace std;

int main(void)
{
	int t = 0;
	cin >> t;

	int x = 0, y = 0, ai = 0;

	for (int i = 0; i < t; i++)
	{
		cin >> ai >> x >> y;
		for (int k = x; k <= ai; k+=x)
		{
			if ( ((k % x) == 0) && ((k % y) != 0) ) 
				cout << k << " ";
		}
		cout << endl;
	}
	return 0;
}