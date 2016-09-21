#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

string convert(string destination, string source)
{
	int counter = 1;
	destination.clear();
	for (int i = 0; i < source.length(); i++)
	{
		if (source[i] != source[i+1]) destination += source[i];
		else 
		{
			while (source[i] == source[i+1])
			{
				counter++;
				i++;
			}
			if (counter == 2) 
			{		
				destination += source[i];
				destination += source[i];
			}
			if (counter > 2) 
			{
				destination += source[i];
				char  *temp = new char[counter];
				sprintf(temp, "%d", counter);
				destination += temp;
			}
			counter = 1;
		}
	}
	return destination;
}

int main()
{
	string word, kword;
	int ilosc_slow;

	cin >> ilosc_slow;

	for (int i = 0; i < ilosc_slow; i++)
	{
		cin >> word;
		kword = convert(kword, word);
		cout << kword << endl;
	}

	return 0;
}