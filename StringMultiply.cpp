/*
	_number class by chrisbe@interia.eu

	This class describes the class _number, which can operate on very big numbers, which
	maximum limit of digits you can change by defining _MAX....

	Class implements simple arithmetics like:
	+  --- addition
	-  --- subtraction
	*  --- multiplying
	/  --- dividing

	Still to do:

	% --- dividing modulo
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

#define _MAX 10000             // maximum number of digits in number ..............................

///////////////////////////////////////////////////////////////////////////////////////////////////
////////// DEFINICJE FUNKCJI POMOCNICZYCH /////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

short int convert(char sign)
{
	return (short int)sign - 48;
}

int count_characters(char *text)
{
	int i = 0;
	while (text[i] != '\0') i++;
	return i;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
/////      DEFINICJA KLASY LICZBOWEJ      /////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

class _number
{
	public:
		_number();
		void _load(char *text);
		void _show();
		void _setsize(int x) { this -> number_of_digits = x; }
		void _moveleft(int x);
		_number operator +(_number n);
		_number operator *(short int x);
		_number operator *(_number n);
	private:
		short int digits[_MAX];
		int number_of_digits;
};

_number::_number()
{
	for (int i = 0; i < _MAX; i++) digits[i] = 0;
	number_of_digits = 0;
}

void _number::_load(char *text)
{
	int temp = count_characters(text);
	for (int i = 0; i < temp; i++) digits[(_MAX + i) - temp] = convert(text[i]);
	number_of_digits = temp;
}

void _number::_show()
{
	for (int i = 0; i < number_of_digits; i++) cout << digits[_MAX - number_of_digits + i];
	cout << endl;
}

void _number::_moveleft(int x)
{
	for (int i = 0; i < this -> number_of_digits; i++)
		this -> digits[_MAX - this -> number_of_digits -1 + i - x] = this -> digits[_MAX - this -> number_of_digits -1 + i];
	for (int i = 0; i < x; i++)
	{
		this -> digits[_MAX - 1 - i] = 0;
		this -> number_of_digits++;
	}
}

_number _number::operator +(_number n)
{
	int temp;
	if (this->number_of_digits >= n.number_of_digits) temp = this->number_of_digits;
	else temp = n.number_of_digits;
	_number _result;
	_result._setsize(temp);
	for (int i = 0; i < temp; i++)
	{
		_result.digits[_MAX - i - 1] += this -> digits[_MAX - i - 1] + n.digits[_MAX - i - 1];
		if (_result.digits[_MAX - 1 - i] > 9)
		{
			_result.digits[_MAX - 1 - i] = _result.digits[_MAX - 1 - i] % 10;
			_result.digits[_MAX - 2 - i] = 1;
			if (i == temp - 1) _result._setsize(temp + 1);
		}
	}
	return _result;
}

_number _number::operator *(short int x)
{
	_number temp;
	short int flag = 0;
	for (int i = 0; i < this -> number_of_digits + 1; i++)
	{
		temp.digits[_MAX - 1 - i] = this -> digits[_MAX - 1 - i] * x + flag;
		if (temp.digits[_MAX - 1 - i] > 9)
		{
			flag = temp.digits[_MAX - 1 - i] / 10;
			temp.digits[_MAX - 1 - i] %= 10;
		}
		else flag = 0;
	}
	if (temp.digits[_MAX - this -> number_of_digits - 1] > 0) temp._setsize(this -> number_of_digits + 1);
	else temp._setsize(this -> number_of_digits);
	return temp;
}

_number _number::operator *(_number n)
{
	_number temp;
	_number suma;

	for (int i = 0; i < n.number_of_digits; i++)
	{
		temp = n * this -> digits[_MAX - 1 - i];
		if (i != 0) temp._moveleft(i);
		temp._show();
		suma = temp + suma;
		suma._show();
	}

	return suma;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
/////////////// FUNKCJA GŁÓWNA ////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

int main(void)
{
	_number x;
	_number y;
	_number result;
	char *text = new char[200];
	cin >> text;
	x._load(text);
	cin >> text;
	y._load(text);
	cout << "----------------------------------------------------" << endl;
	result = x + y;
	result._show();

	result = result * 3;
	result._show();
	cout << "----------------------------------------------------" << endl;
	result = x * y;
	result._show();

	system("pause");
	return 0;
}

