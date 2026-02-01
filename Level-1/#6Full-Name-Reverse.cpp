#include <iostream> 
using namespace std;

//Write a program to ask the user to enter :
//• First Name
//• Last Name
//Then Print Full Name on screen

struct PersonInfo
{
    string FirstName;
    string LastName;
};
PersonInfo ReadInfo()
{
    PersonInfo Info;

    cout << "Please Enter Your First Name?" << endl;
    cin >> Info.FirstName;

    cout << "Please Enter Your Last Name?" << endl;
    cin >> Info.LastName;

    return Info;
}
string GetFullName(PersonInfo Info, bool Reversed)
{
    string FullName = "";

    if (Reversed)
        FullName = Info.LastName + " " + Info.FirstName;
    else
        FullName = Info.FirstName + " " + Info.LastName;

    return FullName;
}
void PrintFullName(string FullName)
{
    cout << "\n Your full name is: " << FullName << endl;
}

int main()
{
    PrintFullName(GetFullName(ReadInfo(), false));
    return 0;
}