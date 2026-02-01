#include <iostream>
using namespace std;

//Write a program to ask the user to enter his / her:
//• Age
//• Driver license
//• Has Recommendation!
//Then Print “Hired” if his\her age is grater than 21 and s / he
//has a driver license, otherwise Print “Rejected”
//Or Hire him\her without conditions!

struct DriverInfo
{
    int Age;
    bool HasDrivingLicense;
    bool HasRecommendation;
};
DriverInfo ReadInfo()
{
    DriverInfo Info;

    cout << "Please Enter Your Age?" << endl;
    cin >> Info.Age;

    cout << "Do you have a driver’s license? (1 for Yes, 0 for No)" << endl;
    cin >> Info.HasDrivingLicense;

    cout << "Do you have a recommendation? (1 for Yes, 0 for No)" << endl;
    cin >> Info.HasRecommendation;

    return Info;
}
bool IsAccepted(DriverInfo Info)
{
    if (Info.HasRecommendation)
    {
        return true;
    }
    else
    {
        return (Info.Age > 21 && Info.HasDrivingLicense);
    }
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