

#include <iostream>
using namespace std;
int ReadPositiveNumber(string meassage) {
    int number;
    do {
        cout << meassage << endl;
        cin >> number;
    } while (number <=0);
    return number;
}
void PrintDigits(int number) {
    int remainder = 0;
     while (number > 0){
        remainder = number % 10;
        number = number / 10;
        cout << remainder << endl;
    }
}
int main()
{
    PrintDigits(ReadPositiveNumber("Enter the Number"));
    return 0;
}
