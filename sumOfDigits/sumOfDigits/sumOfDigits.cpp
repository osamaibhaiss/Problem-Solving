// sumOfDigits.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
using namespace std;

int readpositive(string meassage) {
    int number;
    do {
        cout << meassage << endl;
        cin >> number;
    } while (number <= 0);
    return number;
}
int sumOfDigits(int number) {
    int remainder = 0;
    int sum=0;
    while (number > 0) {
        remainder = number % 10;
        number = number / 10;
        sum += remainder;
    }return sum;
}

int main()
{
   cout<<"sum of digits is:\n" << sumOfDigits(readpositive("enter the number"));

}
