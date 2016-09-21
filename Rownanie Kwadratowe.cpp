#include <stdio.h>
#include <iostream>

using namespace std;

int main(void)
{
	float a, b, c;
	float delta;

	while (cin >> a)
	{
		cin >> b >> c;
		delta = b*b - (4*a*c);
		if (delta == 0) cout << "1\n";
		else if (delta > 0)  cout << "2\n";
		else if (delta < 0)  cout << "0\n";
	}

	return 0;
}
