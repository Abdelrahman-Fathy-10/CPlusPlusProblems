#include <iostream>  
using namespace std;

//Write a program to ask the user to enter his / her:
//• Age
//• Driver license
//Then Print “Hired” if his\her age is grater than 21 and s / he
//has a driver license, otherwise Print “Rejected”

struct DriverInfo
{
    int Age;
    bool HasDrivingLicense;
};
DriverInfo ReadInfo()
{
    DriverInfo Info;

    cout << "Please Enter Your Age?" << endl;
    cin >> Info.Age;

    cout << "Do you have a driver’s license? (1 for Yes, 0 for No)" << endl;
    cin >> Info.HasDrivingLicense;

    return Info;
}
bool IsAccepted(DriverInfo Info)
{
    return (Info.Age > 21 && Info.HasDrivingLicense);
}
void PrintResult(DriverInfo Info)
{
    if (IsAccepted(Info))
        cout << "\n Hired" << endl;
    else
        cout << "\n Rejected" << endl;
}

int main()
{
    PrintResult(ReadInfo());
    return 0;
}