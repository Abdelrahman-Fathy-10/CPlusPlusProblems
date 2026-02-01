#include <iostream>
#include <string>     
using namespace std;

//Write a program to ask the user to enter a number, then
//Print “ODD” if its odd, Or “Even” if its even

enum NumberType { Odd = 1, Even = 2 };

int ReadNumber()
{
    int Num;
    cout << "Please enter a number? " << endl;
    cin >> Num;
    return Num;
}
NumberType CheckNumberType(int Num)
{
    int Result = Num % 2;

    if (Result == 0)
        return NumberType::Even;
    else
        return NumberType::Odd;
}
void PrintNumberType(NumberType NumberType)
{
    if (NumberType == NumberType::Even)
        cout << "\n Number is Even. \n";
    else
        cout << "\n Number is Odd. \n";
}

int main()
{
    PrintNumberType(CheckNumberType(ReadNumber()));
    return 0;
}