// Program Name: All Digits Frequency Counter
// Description : Reads a positive number and prints the frequency of each digit (0-9) present in it.

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

int CountDigitFrequency(short DigitToCheck, int Number)
{
    int Freq = 0;
    while (Number > 0)
    {
        int Remainder = Number % 10;
        Number = Number / 10;
        if (DigitToCheck == Remainder)
            Freq++;
    }
    return Freq;
}

void PrintAllDigitsFrequency(int Number)
{
    cout << endl;
    for (int i = 0; i < 10; i++)
    { 
        int DigitFrequency = CountDigitFrequency(i, Number);
        if (DigitFrequency > 0)
        {
            cout << "Digit " << i << " Frequency is "
                 << DigitFrequency << " Time(s).\n";
        }
    }
}

int main()
{
    int Number = ReadPositiveNumber("Please enter a number:");
    PrintAllDigitsFrequency(Number);
    return 0;
}
