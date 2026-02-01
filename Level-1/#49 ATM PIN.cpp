#include <iostream>
using namespace std;

/*Write a program to read the ATM PIN code from the user, then check if PIN Code = 1234, then show the 
balance to user, otherwise print “Wong PIN” and ask the user to enter the PIN again.
Assume User Balance is 7500
*/

string ReadPinCode()
{
    string PinCode;
    cout << "Please enter PIN code \n";
    cin >> PinCode;
    return PinCode;
}

bool Login()
{
    string PinCode;
    do
    {
        PinCode = ReadPinCode();
        if (PinCode == "1234")
        {
            return true;
        }
        else
        {
            cout << "\nWrong PIN\n";
            system("color 4F");
        }
    } while (PinCode != "1234");

    return false;
}

int main()
{
    if (Login())
    {
        system("color 2F");
        cout << "\nYour account balance is " << 7500 << '\n';
    }

    return 0;
}
