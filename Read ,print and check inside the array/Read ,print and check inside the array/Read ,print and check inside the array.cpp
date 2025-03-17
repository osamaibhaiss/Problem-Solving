/*
Author: Osama Bhais
Description:
This C++ program reads an array of integers from the user, checks how many times a specific number appears in the array, and displays the result.

Functions:
1. ReadPositiveNumber(string Message) - Reads a positive integer from the user.
2. ReadArray(int arr[100], int& arrLength) - Reads an array of integers from the user.
3. PrintArray(int arr[100], int arrLength) - Prints the elements of the array.
4. TimesRepeated(int Number, int arr[100], int arrLength) - Counts how many times a given number appears in the array.

The program:
- Prompts the user to enter the number of elements and then the array elements.
- Asks for a number to check its occurrences in the array.
- Displays the original array.
- Outputs how many times the number appears in the array.
*/
#include <iostream>
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
void ReadArray(int arr[100], int& arrLength)
{
	cout << "\nEnter number of elements:\n";
	cin >> arrLength;
	cout << "\nEnter array elements: \n";
	for (int i = 0; i < arrLength; i++)
	{
		cout << "Element [" << i + 1 << "] : ";
		cin >> arr[i];
	}
	cout << endl;
}
void PrintArray(int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
		cout << arr[i] << " ";
	cout << "\n";
}
int TimesRepeated(int Number, int arr[100], int arrLength)
{
	int count = 0;
	for (int i = 0; i <= arrLength - 1; i++)
	{
		if (Number == arr[i])
		{
			count++;
		}
	}
	return count;
}
int main() {
	int arr[100], arrLength, NumberToCheck;
	ReadArray(arr, arrLength);
	NumberToCheck = ReadPositiveNumber("Enter the number you want to check : ");
		cout << "\nOriginal array: ";
	PrintArray(arr, arrLength);
	cout << "\nNumber " << NumberToCheck;
	cout << " is repeated ";
	cout << TimesRepeated(NumberToCheck, arr, arrLength) << "time(s)\n";
		return 0;
}