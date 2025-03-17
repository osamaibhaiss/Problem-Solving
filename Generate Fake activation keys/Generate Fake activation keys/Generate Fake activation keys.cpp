/*
	Random Key Generator in C++

	This program generates a specified number of random keys, each consisting of
	four groups of four capital letters, separated by dashes (e.g., "ABCD-EFGH-IJKL-MNOP").

	Features:
	- Uses `srand(time(NULL))` to seed the random number generator.
	- Defines an `enum enCharType` to categorize character types.
	- Implements `GenerateWord()` to create random words of a specified length.
	- Implements `GenerateKey()` to format a key in the pattern XXXX-XXXX-XXXX-XXXX.
	- Uses `ReadPositiveNumber()` to prompt the user for input validation.
	- Uses `GenerateKeys()` to generate multiple keys.

	Note:
	- The program prompts the user to input how many keys should be generated.
	- ASCII range used:
		- Capital letters: 65-90 ('A' to 'Z').

	Auther :Osama Bhais

*/
#include <iostream>
#include <string>
#include<cstdlib>
using namespace std;
enum enCharType {
	SamallLetter = 1, CapitalLetter = 2,
	SpecialCharacter = 3, Digit = 4
};
int RandomNumber(int From, int To)
{
	//Function to generate a random number
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}
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
string GenerateWord(enCharType CharType, short Length)
{
	string Word;
	for (int i = 1; i <= Length; i++)
	{
		Word = Word + GetRandomCharacter(CharType);
	}
	return Word;
}
string GenerateKey()
{
	string Key = "";
	Key = GenerateWord(enCharType::CapitalLetter, 4) + "-";
	Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
	Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
	Key = Key + GenerateWord(enCharType::CapitalLetter, 4);
	return Key;
}
void GenerateKeys(short NumberOfKeys)
{
	for (int i = 1; i <= NumberOfKeys; i++)
	{
		cout << "Key [" << i << "] : ";
		cout << GenerateKey() << endl;
	}
}
int main()
{
	//Seeds the random number generator in C++, called only once
	srand((unsigned)time(NULL));
	GenerateKeys(ReadPositiveNumber("Pleaes enter how many keys to generate ? \n "));
		return 0;
}