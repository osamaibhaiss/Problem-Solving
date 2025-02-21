
/**
 * @file pattern_generator.cpp
 * @brief A simple C++ program that prompts the user for a positive number
 *        and prints a pattern based on the input.
 *
 * @details
 * - The user is prompted to enter a positive integer.
 * - The program ensures that the input is valid (positive).
 * - A pattern is printed where each row contains the row number repeated `i` times.
 *
 * Example Output:
 * ```
 * Enter a positive number: 5
 *
 * 1
 * 22
 * 333
 * 4444
 * 55555
 * ```
 */
#include <iostream>
using namespace std;
int PositiveNumber(string meassage) {
	int number=0;
	do {
		cout << meassage;
		cin >> number;
	}while (number <= 0);
	return number;
}
void printpatternNumber(int number) {
	cout << "\n";
	for (int i = 1; i <= number; i++) {
		
		for (int j = 1; j  <= i; j++) {
			cout << i;
		}
		cout << endl;
	}
}
int main()
{
	int number = PositiveNumber("Enter a positive number");
	printpatternNumber(number);
}
