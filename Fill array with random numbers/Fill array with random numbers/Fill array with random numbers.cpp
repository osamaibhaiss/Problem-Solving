/*
Author: Osama Bhais

Description:
This C++ program generates an array of random numbers and prints them.

Functions:
1. RandomNumber(int from, int to) - Generates a random number between 'from' and 'to'.
2. fillArray(int arr[100], int &arrayLength) - Fills an array with random numbers.
3. printArray(int arr[100], int length) - Prints the elements of the array.

The program:
- Asks the user for the number of elements.
- Fills the array with random numbers from 1 to 100.
- Prints the generated numbers.

Note:
- The array index in 'fillArray' has an off-by-one error that may cause issues.
- The program initializes the random seed using `srand(time(NULL))` in `main()`.
*/
#include <iostream>
using namespace std;

int RandomNumber(int from, int to) {
	int randNumber = rand() % (to - from + 1) + from;
	return randNumber;
}
void fillArray(int arr[100], int &arrayLength) {
	cout << "\n Enter the Number of Elements \n";
	cin >> arrayLength;
	for (int i = 0; i <= arrayLength; i++) {
		arr[i] = RandomNumber(1, 100);
	}
}
void printArray(int arr[100], int length) {
	cout << "The Elements of the array with lenght of" << length << ": " << endl;
	for (int i = 0; i < length; i++) {
		cout << arr[i];
		cout << endl;
	}
}
int main()
{
	srand((unsigned)time(NULL));
	int arr[100], arrLength;
	fillArray(arr, arrLength);
	printArray(arr, arrLength);
	return 0;
}
