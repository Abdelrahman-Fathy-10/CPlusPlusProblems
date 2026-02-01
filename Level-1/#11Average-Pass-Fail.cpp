#include <iostream>
#include <string> 
using namespace std;

//Write a program to ask the user to enter :
//• Mark1, Mark2, Mark3
//Then Print the Average of entered Marks, and print “PASS” if average >= 50, otherwise print “FAIL

enum PassFail { Pass = 1, Fail = 2 };

void ReadNumbers(int& Mark1, int& Mark2, int& Mark3)
{
    cout << "Please enter Mark 1 ? " << endl;
    cin >> Mark1;

    cout << "Please enter Mark 2 ? " << endl;
    cin >> Mark2;

    cout << "Please enter Mark 3 ? " << endl;
    cin >> Mark3;
}
int SumOf3Marks(int Mark1, int Mark2, int Mark3)
{
    return Mark1 + Mark2 + Mark3;
}
float CalculateAverage(int Mark1, int Mark2, int Mark3)
{
    return (float)SumOf3Marks(Mark1, Mark2, Mark3) / 3;
}
PassFail CheckAverage(float Average)
{
    if (Average >= 50)
        return PassFail::Pass;
    else
        return PassFail::Fail;
}
void PrintResults(float Average)
{
    cout << "\n Your Average is: " << Average << endl;

    if (CheckAverage(Average) == PassFail::Pass)
        cout << "\n You Passed" << endl;
    else
        cout << "\n You Failed" << endl;
}

int main()
{
    int Mark1, Mark2, Mark3;
    ReadNumbers(Mark1, Mark2, Mark3);
    PrintResults(CalculateAverage(Mark1, Mark2, Mark3));
    return 0;
}