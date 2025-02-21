
/*
    Random Number Generator in C++

    This program generates random numbers within a specified range using the `rand()` function.
    It defines a function `RandomNumber(int from, int to)` that returns a random number between `from` and `to`.

    Features:
    - Uses `srand(time(NULL))` to seed the random number generator for better randomness.
    - Generates and prints three random numbers between 70 and 90.
    - Uses the modulus operator to ensure the numbers stay within the given range.

    Note:
    - The `rand()` function generates pseudo-random numbers.
    - The seeding process ensures different outputs in each program run.
*/
#include <iostream>
#include <cstdlib>
using namespace std;
int RandomNumber(int from, int to) {
    int randNumber = rand() % (to - from + 1) + from;
    return randNumber;
}
int main()
{
    srand((unsigned)time(NULL));
   /* cout << rand() % 10;
    cout << endl;
    cout << rand() % 10;
    cout << endl;

    cout << rand() % 10;
    cout << endl;

    cout << rand() % 10;
    */
    
    cout << RandomNumber(70, 90) << endl;
    cout << RandomNumber(70, 90) << endl;
    cout << RandomNumber(70, 90) << endl;
    return 0;
    
   

}
