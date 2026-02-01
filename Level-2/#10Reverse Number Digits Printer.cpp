// Program Name: Reverse Number Digits Printer
// Description : Reads a positive number, reverses it, and prints each digit of the reversed number on a new line.

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

int ReverseNumber(int Number)
{
    int Reversed = 0;
    while (Number > 0)
    {
        int Remainder = Number % 10;
        Number = Number / 10;
        Reversed = Reversed * 10 + Remainder;
    }
    return Reversed;
}

void PrintDigits(int Number)
{
    while (Number > 0)
    {
        int Remainder = Number % 10;
        Number = Number / 10;
        cout << Remainder << endl;
    }
}

int main()
{
    PrintDigits(ReverseNumber(ReadPositiveNumber("Please enter a positive number:")));
    return 0;
}
