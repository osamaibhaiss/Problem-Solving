/**
 * @file generate_words.cpp
 * @brief A program that generates all three-letter uppercase words from AAA to ZZZ.
 *
 * @details
 * - Uses three nested loops to iterate through ASCII values of 'A' (65) to 'Z' (90).
 * - Constructs three-letter combinations and prints them.
 * - Separates groups with a line for better readability.
 * - Counts and displays the total number of words at the end.
 * 
AAA
AAB
AAC
...
ZZX
ZZY
ZZZ

____________________________
The number of possible probabilities is: 17576
 */
#include <iostream>
#include <string>
using namespace std;
void PrintWordsFromAAAtoZZZ()
{
	int counter = 0;
	cout << "\n";
	string word = "";
	for (int i = 65; i <= 90; i++)
	{
		for (int j = 65; j <= 90; j++)
		{
			for (int k = 65; k <= 90; k++)
			{
				word = word + char(i);
				word = word + char(j);
				word = word + char(k);
				cout << word << endl;
				word = "";
				counter++;
			}
		}
		
		cout << "\n____________________________\n";
		
	}
	cout << "The number of possible probabilities is: " << counter;
}
int main()
{
	PrintWordsFromAAAtoZZZ();
	return 0;
}