#include <iostream>
#include <stdlib.h>

using namespace std;

int count_characters(char *text)
{
	int i = 0;
	while (text[i] != '\0') i++;
	return i;
}

class c_Big_Number
{
	public:
		c_Big_Number() { };
		c_Big_Number(char *text);
		c_Big_Number(const c_Big_Number &object);
		~c_Big_Number();
		void Print_Number();
		int Get_Number_Of_Digits()           { return this -> number_of_digits; }
		void Set_Number_Of_Digits(int x);
		void Set_To_Zero();

		short int *numbers;
		int number_of_digits;
};

c_Big_Number::c_Big_Number(char *text)
{
	this -> number_of_digits = count_characters(text);
	this -> numbers = new short int [this -> number_of_digits];

	for (int i = 0; i < this -> number_of_digits; i++)
		this -> numbers[i] = (short int)text[i] - 48;
}

c_Big_Number::c_Big_Number(const c_Big_Number &object)
{
	number_of_digits = object.number_of_digits;
	numbers = new short int [object.number_of_digits];
	*numbers = *object.numbers;
}

c_Big_Number::~c_Big_Number()
{
	delete [] this->numbers;
}

void c_Big_Number::Print_Number()
{
	for (int i = 0; i < this->number_of_digits; i++) cout << this -> numbers[i];
	cout << "\n";
}

void c_Big_Number::Set_Number_Of_Digits(int x)
{
	this -> number_of_digits = x;
	this -> numbers = new short int [this->number_of_digits];
}

void c_Big_Number::Set_To_Zero()
{
	for (int i = 0; i < this -> number_of_digits; i++)
		this -> numbers[i] = 0;
}

c_Big_Number* add_numbers(c_Big_Number num1, c_Big_Number num2)
{
	int i = num1.Get_Number_Of_Digits() - num2.Get_Number_Of_Digits();
	if (i < 0) i = -i;

	c_Big_Number *temp = new c_Big_Number;
	temp -> Set_Number_Of_Digits(num1.Get_Number_Of_Digits() + 1);
	temp -> Set_To_Zero();

	for (int k = 0; k < i; k++)
	{
		temp -> numbers[temp->number_of_digits - k] += num1.numbers[num1.number_of_digits - k] + num2.numbers[num2.number_of_digits - k];
		if (temp -> numbers[temp->number_of_digits - k] > 9) temp -> numbers[temp->number_of_digits - (k + 1)] = 1;
	}

	return temp;
}

int main(void)
{
	char a[1000];
	char b[1000];
	cin >> a;
	cin >> b;
	c_Big_Number numer1(a);
	c_Big_Number numer2(b);
	numer1.Print_Number();
	numer2.Print_Number();
	c_Big_Number *wynik = new c_Big_Number;
	wynik =  add_numbers(numer1, numer2);
	wynik -> Print_Number();

	system("pause");
	return 0;
}