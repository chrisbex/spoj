#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int ilosc_cyfr(long long int x)
{
	int a = 1;
	while ((x = x / 11) != 0) a++;
	return a;
}

void eleven(long long int x)
{
	int k = ilosc_cyfr(x);
	char *buf = new char[k+1];
	for (int i = 0; i < k; i++)
	{
		buf[i] = (x % 11) + 48;
		if (buf[i] == 58) buf[i] = 'A';
		x = x / 11;
	}
	buf[k] = '\0';
	for (int i = 0; i < k; i++) printf("%c", buf[k-i-1]);
	cout << endl;
}

int main(void)
{
	int t;
	cin >> t;

	long long int liczba;

	for (int i = 0; i < t; i++)
	{
		cin >> liczba;
		printf("%X ", liczba);
		eleven(liczba);
	}

	system("pause");
	return 0;
}