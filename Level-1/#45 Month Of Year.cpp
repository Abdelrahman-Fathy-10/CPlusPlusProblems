#include <iostream>
#include <string>

using namespace std;

/*Write a program to ask the user to enter:
• Month
Then print the day as follows:
• 1 Print January
• 2 Print February
• 3 Print March
• 4 Print April
• 5 Print May
• 6 Print June
• 7 Print July
• 8 Print August
• 9 Print September
• 10 Print October
• 11 Print November
• 12 December
• Otherwise print “Wrong Month” and ask the use to enter the Month again*/

enum MonthOfYear {
    Jan = 1, Feb = 2, Mar = 3, Apr = 4, May = 5,
    Jun = 6, Jul = 7, Aug = 8, Sep = 9, Oct = 10,
    Nov = 11, Dec = 12
};

int ReadNumberInRange(string Message, int From, int To)
{
    int Number = 0;
    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number < From || Number > To);

    return Number;
}

MonthOfYear ReadMonthOfYear()
{
    return (MonthOfYear)ReadNumberInRange("Please enter a month [1 to 12]:", 1, 12);
}

string GetMonthOfYear(MonthOfYear Month)
{
    switch (Month)
    {
    case MonthOfYear::Jan:
        return "January";
    case MonthOfYear::Feb:
        return "February";
    case MonthOfYear::Mar:
        return "March";
    case MonthOfYear::Apr:
        return "April";
    case MonthOfYear::May:
        return "May";
    case MonthOfYear::Jun:
        return "June";
    case MonthOfYear::Jul:
        return "July";
    case MonthOfYear::Aug:
        return "August";
    case MonthOfYear::Sep:
        return "September";
    case MonthOfYear::Oct:
        return "October";
    case MonthOfYear::Nov:
        return "November";
    case MonthOfYear::Dec:
        return "December";
    default:
        return "Not a valid Month";
    }
}

int main()
{
    cout << GetMonthOfYear(ReadMonthOfYear()) << endl;
    return 0;
}
