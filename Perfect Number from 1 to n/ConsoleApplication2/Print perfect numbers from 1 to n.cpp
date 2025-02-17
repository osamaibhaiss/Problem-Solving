/*
	Program: Perfect Number Finder
	Description:
	This program prompts the user to enter a positive number (N) and then finds all
	perfect numbers from 1 to N. A perfect number is a number that is equal to the
	sum of its proper divisors (excluding itself).

	Functions:
	- ReadPositiveNumber: Reads and validates a positive integer input from the user.
	- isPerfectNumber: Checks whether a given number is a perfect number.
	- PrintPerfectNumbersFrom1ToN: Iterates from 1 to N and prints all perfect numbers.

	The program ensures valid user input and accurately identifies and prints
	perfect numbers within the given range.

	Author: Osama Bhais*/

#include <iostream>
#include <string>
using namespace std;
int ReadPositiveNumber(string Message)
{
	int Number = 0;
	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}
bool isPerfectNumber(int Number)
{
	int Sum = 0;
	for (int i = 1; i < Number; i++)
	{
		if (Number % i == 0)
			Sum += i;
	}
	return Number == Sum;
}
void PrintPerfectNumbersFrom1ToN(int Number)
{
	for (int i = 1; i <= Number; i++)
	{
		if (isPerfectNumber(i))
		{
			cout << i << endl;
		}
	}
}
int main()
{
	PrintPerfectNumbersFrom1ToN(ReadPositiveNumber("Please enter a positive number ? "));
		return 0;
}