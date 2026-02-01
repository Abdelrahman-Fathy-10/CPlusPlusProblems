// Program Name: Reverse Number
// Description : Reads a positive number and prints its digits in reverse order.

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

int main()
{
    cout << "\nReverse is:\n"
         << ReverseNumber(ReadPositiveNumber("Please enter a positive number:"))
         << "\n";
    return 0;
}
