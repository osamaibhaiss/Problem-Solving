/*
Author: Osama Bhais
Description:
This C++ program generates an array of random numbers, prints them, and finds the maximum number in the array.

Functions:
1. RandomNumber(int From, int To) - Generates a random number between 'From' and 'To'.
2. FillArrayWithRandomNumbers(int arr[100], int& arrLength) - Fills an array with random numbers.
3. PrintArray(int arr[100], int arrLength) - Prints the elements of the array.
4. MaxNumberInArray(int arr[100], int arrLength) - Finds the maximum number in the array.

The program:
- Asks the user for the number of elements.
- Fills the array with random numbers between 1 and 100.
- Prints the array elements.
- Finds and prints the maximum number in the array.

Note:
- The program initializes the random seed using `srand(time(NULL))` in `main()`.
*/
#include <iostream>
using namespace std;
int RandomNumber(int From, int To)
{
	//Function to generate a random number
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}
void FillArrayWithRandomNumbers(int arr[100], int& arrLength)
{
	cout << "\nEnter number of elements:\n";
	cin >> arrLength;
	for (int i = 0; i < arrLength; i++)
		arr[i] = RandomNumber(1, 100);
}
void PrintArray(int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
		cout << arr[i] << " ";
	cout << "\n";
}
int MaxNumberInArray(int arr[100], int arrLength)
{
	int Max = 0;
	for (int i = 0; i < arrLength; i++)
	{
		if (arr[i] > Max)
		{
			Max = arr[i];
		}
	}
	return Max;
}
int main() {
	
	srand((unsigned)time(NULL));
	int arr[100], arrLength;
	FillArrayWithRandomNumbers(arr, arrLength);
	cout << "\nArray Elements: ";
	PrintArray(arr, arrLength);
	cout << "\nMax Number is : ";
	cout << MaxNumberInArray(arr, arrLength) << endl;
	return 0;
}