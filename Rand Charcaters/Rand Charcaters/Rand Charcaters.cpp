/*
	Random Character Generator in C++

	This program generates random characters from different character types:
	- Small letters (a-z)
	- Capital letters (A-Z)
	- Special characters (!, @, #, etc.)
	- Digits (0-9)

	Features:
	- Uses `srand(time(NULL))` to seed the random number generator.
	- Defines an `enum enCharType` to categorize character types.
	- Implements `GetRandomCharacter()` to generate random characters based on the selected type.
	- Uses `RandomNumber(int From, int To)` to generate numbers within ASCII ranges.

	Note:
	- ASCII ranges:
		- Lowercase letters: 97-122
		- Uppercase letters: 65-90
		- Special characters: 33-47
		- Digits: 48-57
	- The program prints one random character from each category.

	Auther : Osama Bhais

*/
#include <iostream>
#include <string>
using namespace std;
int RandomNumber(int From, int To)
{
	//Function to generate a random number
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}
enum enCharType {
	SamallLetter = 1, CapitalLetter = 2,
	SpecialCharacter = 3, Digit = 4
};
char GetRandomCharacter(enCharType CharType)
{
	switch (CharType)
	{
	case enCharType::SamallLetter:
	{
		return char(RandomNumber(97, 122));
		break;
	}
	case enCharType::CapitalLetter:
	{
		return char(RandomNumber(65, 90));
		break;
	}
	case enCharType::SpecialCharacter:
	{
		return char(RandomNumber(33, 47));
		break;
	}
	case enCharType::Digit:
	{
		return char(RandomNumber(48, 57));
		break;
	}
	}
}
int main()
{
	//Seeds the random number generator in C++, called only once
	srand((unsigned)time(NULL));
	cout << GetRandomCharacter(enCharType::SamallLetter) << endl;
	cout << GetRandomCharacter(enCharType::CapitalLetter) << endl;
	cout << GetRandomCharacter(enCharType::SpecialCharacter) <<
		endl;
	cout << GetRandomCharacter(enCharType::Digit) << endl;
	return 0;
}