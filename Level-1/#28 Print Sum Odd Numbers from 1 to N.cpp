#include <iostream> 
#include <string>   
using namespace std;

/*Write a program to Sum odd numbers from 1 to N*/

enum OddOrEven { Odd = 1, Even = 2 };

int ReadNumber()
{
    int Number; 

    cout << "Please enter a number? " << endl;
    cin >> Number;

    return Number; 
}
OddOrEven CheckOddOrEven(int Number)
{
    if (Number % 2 != 0)
        return OddOrEven::Odd;
    else
        return OddOrEven::Even;
}

int SumOddNumbersFrom1toN_UsingWhile(int N)
{
    int Counter = 0; 
    int Sum = 0;

    cout << "Sum odd numbers using While Statement:\n";

    while (Counter < N)
    {
        Counter++; 

        if (CheckOddOrEven(Counter) == OddOrEven::Odd)
        {
            Sum += Counter;
        }
    }
    return Sum;
}
int SumOddNumbersFrom1toN_UsingDoWhile(int N)
{
    int Counter = 0; 
    int Sum = 0; 

    cout << "Sum odd numbers using Do..While Statement:\n";

    do
    {
        Counter++; 

        if (CheckOddOrEven(Counter) == enOddOrEven::Odd)
        {
            Sum += Counter;
        }
    } while (Counter < N); 

    return Sum;
}
int SumOddNumbersFrom1toN_UsingFor(int N)
{
    int Sum = 0;

    cout << "Sum odd numbers using For Statement:\n";

    for (int Counter = 1; Counter <= N; Counter++)
    {
        if (CheckOddOrEven(Counter) == enOddOrEven::Odd)
        {
            Sum += Counter;
        }
    }

    return Sum;
}
int main()
{
    int N = ReadNumber();

    cout << SumOddNumbersFrom1toN_UsingWhile(N) << endl;
    cout << SumOddNumbersFrom1toN_UsingDoWhile(N) << endl;
    cout << SumOddNumbersFrom1toN_UsingFor(N) << endl;

    return 0; 
}