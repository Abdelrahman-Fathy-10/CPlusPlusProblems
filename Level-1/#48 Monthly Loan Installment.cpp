#include <iostream>
#include <string>

using namespace std;

/*Write a program to read a LoanAmount and ask you how many months you need to settle the loan, then 
calculate the monthly installment amount.*/

float ReadPositiveNumber(string Message)
{
    float Number = 0;

    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);

    return Number;
}

float TotalMonths(float LoanAmount, float MonthlyInstallment)
{
    return LoanAmount / MonthlyInstallment;
}

int main()
{
    float LoanAmount = ReadPositiveNumber("Please Enter Loan Amount?");
    float MonthlyInstallment = ReadPositiveNumber("Please Enter Monthly Installment?");

    cout << "\nTotal Months to pay = " << TotalMonths(LoanAmount, MonthlyInstallment) << endl;

    return 0;
}
