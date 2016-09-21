#include <iostream>
#include <stdio.h>

using namespace std;

bool check_palindrome(int x)
{
	char temp[80];
	sprintf(temp, "%d", x);
	int i = 0;
	while (temp[i] != '\0') i++;
	for (int k = 0; k < i/2; k++)
	{
		if (temp[k] == temp[i-k-1]) continue;
		else return false;
	}
	return true;
}

int convert(int x)
{
	char temp[80], temp2[80];
	sprintf(temp, "%d", x);
	int i = 0;
	while (temp[i] != '\0') i++;
	for (int k = 0; k < i; k++)
		temp2[k] = temp[i-k-1];
	sscanf(temp2, "%d", &i);
	return i + x;
}	

int main()
{
	int ilosc_prob;
	cin >> ilosc_prob;
	int liczba;

	for (int i = 0; i < ilosc_prob; i++)
	{
		int counter = 0;
		cin >> liczba;
		while (check_palindrome(liczba) != true)
		{
			liczba = convert(liczba);
			counter++;
		}
		cout << liczba << " " << counter << endl;
	}

	return 0;
}