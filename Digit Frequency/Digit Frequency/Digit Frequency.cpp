/*
    Program: Digit Frequency Counter
    Description:
    This program prompts the user to enter a positive integer and a single digit (0-9).
    It then calculates and displays the frequency of that digit within the given number.

    Functions:
    - ReadPositiveNumber: Reads a positive integer from the user and ensures valid input.
    - FrequencyDigit: Counts how many times a specific digit appears in a given number.

    The program ensures that the user enters valid input and provides an accurate count
    of the digit occurrences.

    Author: Osama Bhais*/

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

int FrequencyDigit(int number, short int digit)
{
    int counter = 0, remainder = 0; 

    do
    {
        remainder = number % 10;
        number = number / 10;
        if (digit == remainder)
        {
            counter++;
        }
    } while (number > 0);

    return counter;
}

int main()
{
    int Number = ReadPositiveNumber("Please enter the main number: ");

    int DigitToCheck;
    
        DigitToCheck = ReadPositiveNumber("Please enter one digit to check: ");
     

    cout << "\nDigit " << DigitToCheck << " Frequency is "
        << FrequencyDigit(Number, DigitToCheck) << " Time(s).\n";

    return 0;
}
