#include <iostream>
using namespace std;

/*Write a program to read the ATM PIN code from the user, then check if PIN Code = 1234, then show the balance 
to user, otherwise print “Wong PIN” and ask the user to enter the PIN again. 
Only allow user to enter the PIN 3 times, if fails, print “Card is locked!”
Assume User Balance is 7500*/

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
    int Counter = 3;

    do
    {
        Counter--;
        PinCode = ReadPinCode();

        if (PinCode == "1234")
        {
            return true;
        }
        else
        {
            cout << "\nWrong PIN, you have " << Counter << " more tries\n";
        }

    } while (Counter >= 1 && PinCode != "1234");

    return false;
}

int main()
{
    if (Login())
    {
        system("color 2F");
        cout << "\nYour account balance is " << 7500 << '\n';
    }
    else
    {
        system("color 4F");
        cout << "\nYour card is blocked. Call the bank for help.\n";
    }

    return 0;
}
