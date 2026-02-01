// Program Name: Reverse Digits Printer
// Description : Takes a positive integer and prints its digits in reverse order, each on a new line.

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
    PrintDigits(ReadPositiveNumber("Please enter a positive number:"));
    return 0;
}
