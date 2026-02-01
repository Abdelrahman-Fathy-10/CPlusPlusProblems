#include <iostream>
#include <string>  
using namespace std;

//Write a program to ask the user to enter :
//• Mark
//Then Print the “PASS” if mark >= 50, otherwise print “Fail

enum PassFail {Pass , Fail};

int ReadMark()
{
    int Mark;

    cout << "Please enter your mark? " << endl;

    cin >> Mark;

    return Mark;
}
PassFail CheckMark(int Mark)
{
    if (Mark >= 50)
        return PassFail::Pass;
    else
        return PassFail::Fail;
}
void PrintResults(int Mark)
{
    if (CheckMark(Mark) == PassFail::Pass)
        cout << "\n You Passed" << endl;
    else
        cout << "\n You Failed" << endl;
}

int main()
{
    PrintResults(ReadMark());
    return 0;
}