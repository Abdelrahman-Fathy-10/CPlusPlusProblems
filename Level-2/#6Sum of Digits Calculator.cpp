// Program Name: Sum of Digits Calculator
// Description : Reads a positive number and calculates the sum of its digits.

#include <iostream>
#include <string>

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

int SumOfDigits(int Number)
{
    int Sum = 0;
    while (Number > 0)
    {
        int Remainder = Number % 10;
        Number = Number / 10;
        Sum += Remainder;
    }
    return Sum;
}

int main()
{
    cout << "\nSum of Digits = " 
         << SumOfDigits(ReadPositiveNumber("Please enter a positive number:"))
         << "\n";
    return 0;
}
