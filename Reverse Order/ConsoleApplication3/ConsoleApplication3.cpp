/*
    Program: Reverse a Number
    Description:
    This program prompts the user to enter a positive integer and then reverses its digits.
    The reversed number is then displayed as output.

    Functions:
    - ReadPositiveNumber: Reads and validates a positive integer input from the user.
    - reverseNumber: Reverses the digits of the given number and returns the reversed value.

    The program ensures valid user input and correctly reverses the number.

    Author: Osama Bhais*/
#include <iostream>
using namespace std;
int ReadPositiveNumber(string Message)
{
    int Number ;
    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}
int reerseNumber(int number) {
    int remainder = 0,  number2 = 0;
    while (number > 0) {
        remainder = number % 10;
        number = number / 10;
        number2 = number2 * 10 + remainder;
    }
    return number2;
}
int main()
{
    cout << "reverse number = " << reerseNumber(ReadPositiveNumber("Enter a Positive Number"));
    return 0;

}
