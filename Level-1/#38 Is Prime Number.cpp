#include <iostream>  
#include <string>    
#include <cmath>   
using namespace std; 

/*Write a program to read a number and check if it is a prime number or not*/

enum PrimNotPrime { Prime = 1, NotPrime = 2 };

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

PrimNotPrime CheckPrime(int Number)
{
    if (Number < 2)
        return PrimNotPrime::NotPrime;

    int M = (int)sqrt(Number);

    for (int Counter = 2; Counter <= M; Counter++)
    {
        if (Number % Counter == 0)
            return PrimNotPrime::NotPrime;
    }

    return PrimNotPrime::Prime;
}

void PrintNumberType(int Number)
{
    switch (CheckPrime(Number))
    {
    case PrimNotPrime::Prime:
        cout << "The number is Prime\n";
        break;
    case PrimNotPrime::NotPrime:
        cout << "The number is Not Prime\n";
        break;
    }
}

int main()
{

    PrintNumberType(ReadPositiveNumber("Please enter a positive number?"));

    return 0;
}