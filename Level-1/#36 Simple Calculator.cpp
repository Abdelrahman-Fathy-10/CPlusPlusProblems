#include <iostream>
#include <string>   
using namespace std; 

/*Write a program to ask the user to enter:
• Number1
• Number 2
• OperationType
Then perform the calculation according to the Operation Type as follows:
• “+” : add the two numbers.
• “-” : Subtract the two numbers.
• “*” : Multiply the two numbers.
• “/” : Divide the two numbers*/

enum OperationType { Add = '+', Subtract = '-', Multiply = '*', Divide = '/' };

float ReadNumber(string Message)
{
    float Number = 0;

    cout << Message << endl;
    cin >> Number;

    return Number;
}

OperationType ReadOpType()
{
    char OT = '+';

    cout << "Please enter Operation Type ( +, - , * , / )?\n";
    cin >> OT;

    return (OperationType)OT;
}

float Calculate(float Number1, float Number2, OperationType OpType)
{
    switch (OpType)
    {
    case OperationType::Add:
        return Number1 + Number2;  
    case OperationType::Subtract:
        return Number1 - Number2;
    case OperationType::Multiply:
        return Number1 * Number2;  
    case OperationType::Divide:
        return Number1 / Number2;
    default:
        return Number1 + Number2; 
    }
}

int main()
{
    float Number1 = ReadNumber("Please enter the first number?");
    float Number2 = ReadNumber("Please enter the second number?");

    OperationType OpType = ReadOpType();

    cout << endl << "Result = " << Calculate(Number1, Number2, OpType) << endl;

    return 0;
}