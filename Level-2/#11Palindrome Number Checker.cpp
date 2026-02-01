// Program Name: Palindrome Number Checker
// Description : Reads a positive number and checks whether it is a palindrome.

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

bool IsPalindromeNumber(int Number)
{
    return Number == ReverseNumber(Number);
}

int main()
{
    if (IsPalindromeNumber(ReadPositiveNumber("Please enter a positive number:")))
        cout << "\nYes, it is a Palindrome number.\n";
    else
        cout << "\nNo, it is NOT a Palindrome number.\n";

    return 0;
}
