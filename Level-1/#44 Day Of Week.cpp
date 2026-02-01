#include <iostream>
#include <string>

using namespace std;

/*Write a program to ask the user to enter:
• Day
Then print the day as follows:
• 1 Print Sunday
• 2 Print Monday
• 3 Print Tuesday
• 4 Print Wednesday
• 5 Print Thursday
• 6 Print Friday
• 7 Print Saturday
• Otherwise print “Wrong Day” and ask the use to enter the day again.*/

enum DayOfWeek { Sat = 1, Sun = 2, Mon = 3, Tue = 4, Wed = 5, Thu = 6, Fri = 7 };

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

DayOfWeek ReadDayOfWeek()
{
    return (DayOfWeek)ReadNumberInRange(
        "Please enter day number (Sat=1, Sun=2, Mon=3, Tue=4, Wed=5, Thu=6, Fri=7)?",
        1, 7);
}

string GetDayOfWeek(DayOfWeek Day)
{
    switch (Day)
    {
    case DayOfWeek::Sat:
        return "Saturday";
    case DayOfWeek::Sun:
        return "Sunday";
    case DayOfWeek::Mon:
        return "Monday";
    case DayOfWeek::Tue:
        return "Tuesday";
    case DayOfWeek::Wed:
        return "Wednesday";
    case DayOfWeek::Thu:
        return "Thursday";
    case DayOfWeek::Fri:
        return "Friday";
    default:
        return "Not a valid Day";
    }
}

int main()
{
    cout << GetDayOfWeek(ReadDayOfWeek()) << endl;
    return 0;
}
