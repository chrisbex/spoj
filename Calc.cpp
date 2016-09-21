#include <iostream>

using namespace std;

int main(void)
{
	int a, b, result;
	char choose;
	do 
	{
		if ((cin >> choose).eof() == 1) break;
		cin >> a >> b;
		switch ( choose )
		{
			case '+' : { result = a + b; break; }
			case '-' : { result = a - b; break; }
			case '*' : { result = a * b; break; }
			case '/' : { result = a / b; break; }
			case '%' : { result = a % b; break; }
		}
		cout << result << endl;
	} while (choose == '+' || choose == '-' || choose == '*' || choose == '/' || choose == '%');

	return 0;
}