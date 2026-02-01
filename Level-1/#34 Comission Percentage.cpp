#include <iostream>  
#include <string>  
using namespace std;

/*Write a program to ask the user to enter:
• TotalSales
The commission is calculated as one percentage * the total sales amount, all you need is to decide which percentage 
to use of the following:
• > 1000,000    Percentage is 1%
• > 500K to 1M  Percentage is 2%
• > 100K  – 500K Percentage is 3%
• > 50K to 100K  Percentage is 5%
• Otherwise  Percentage is 0%*/

float ReadTotalSales()
{
    float TotalSales;

    cout << "Please enter Total Sales? " << endl;
    cin >> TotalSales;

    return TotalSales;
}

float GetCommissionPercentage(float TotalSales)
{
    if (TotalSales >= 1000000)
        return 0.01;
    else if (TotalSales >= 500000)
        return 0.02; 
    else if (TotalSales >= 100000)
        return 0.03;
    else if (TotalSales >= 50000)
        return 0.05;
    else
        return 0.00;
}

float CalculateTotalCommission(float TotalSales)
{
    return GetCommissionPercentage(TotalSales) * TotalSales;
}

int main()
{
    float TotalSales = ReadTotalSales();

    cout << endl << "Commission Percentage = " << GetCommissionPercentage(TotalSales) * 100 << "%" << endl;

    cout << endl << "Total Commission = " << CalculateTotalCommission(TotalSales) << endl;

    return 0;
}