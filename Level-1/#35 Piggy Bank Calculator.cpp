#include <iostream>  
#include <string>   
using namespace std;

/*Write a program to ask the user to enter:
• Pennies, Nickels, Dimes, Quarters, Dollars
Then calculate the total pennies , total dollars and print them on screen
giving that:
• Penny = 1
• Nickel = 5
• Dime = 10
• Quarter = 25
• Dollar = 100*/

struct PiggyBankContent
{
    int Pennies, Nickels, Dimes, Quarters, Dollars;
};

PiggyBankContent ReadPiggyBankContent()
{
    PiggyBankContent PiggyBankContent;

    cout << "Please enter the total number of Pennies: " << endl;
    cin >> PiggyBankContent.Pennies;
    cout << "Please enter the total number of Nickels: " << endl;
    cin >> PiggyBankContent.Nickels;
    cout << "Please enter the total number of Dimes: " << endl;
    cin >> PiggyBankContent.Dimes;
    cout << "Please enter the total number of Quarters: " << endl;
    cin >> PiggyBankContent.Quarters;
    cout << "Please enter the total number of Dollar bills: " << endl;
    cin >> PiggyBankContent.Dollars;

    return PiggyBankContent;
}

int CalculateTotalPennies(PiggyBankContent PiggyBankContent)
{
    int TotalPennies = PiggyBankContent.Pennies * 1
        + PiggyBankContent.Nickels * 5
        + PiggyBankContent.Dimes * 10
        + PiggyBankContent.Quarters * 25
        + PiggyBankContent.Dollars * 100;

    return TotalPennies; 
}

int main()
{
    int TotalPennies = CalculateTotalPennies(ReadPiggyBankContent());

    cout << endl << "Total Pennies = " << TotalPennies << endl;

    cout << endl << "Total Dollars = $" << (float)TotalPennies / 100 << endl;

    return 0;
}