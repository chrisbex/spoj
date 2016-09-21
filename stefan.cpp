#include <iostream>
#include <stdio.h>

using namespace std;

int main(void)
{
	int t = 0;
	cin >> t;
	
	long long double zysk_max = 0;
	int zysk = 0;

	for (int i = 0; i < t; i++)
	{
		bool flag = true;
		cin >> zysk;
		if (zysk_max + zysk > zysk_max)
		{
			zysk_max += zysk;
			flag = true;
		}
		else flag = false;
	}

	system("pause");
	return 0;
}