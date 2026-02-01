#include <iostream>
#include <string>
#include <cmath>

using namespace std;

/*Write a program that inputs the number of seconds  and changes it to days, hours, minutes, and second*/

struct TaskDuration
{
    int NumberOfDays, NumberOfHours, NumberOfMinutes, NumberOfSeconds;
};

int ReadPositiveNumber(string Message)
{
    int Number = 0;
    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);

    return Number;
}

TaskDuration SecondsToTaskDuration(int TotalSeconds)
{
    TaskDuration Duration;

    const int SecondsPerDay = 24 * 60 * 60;
    const int SecondsPerHour = 60 * 60;
    const int SecondsPerMinute = 60;

    int Remainder = 0;

    Duration.NumberOfDays = TotalSeconds / SecondsPerDay;
    Remainder = TotalSeconds % SecondsPerDay;

    Duration.NumberOfHours = Remainder / SecondsPerHour;
    Remainder = Remainder % SecondsPerHour;

    Duration.NumberOfMinutes = Remainder / SecondsPerMinute;
    Remainder = Remainder % SecondsPerMinute;

    Duration.NumberOfSeconds = Remainder;

    return Duration;
}

void PrintTaskDurationDetails(TaskDuration Duration)
{
    cout << "\n";
    cout << Duration.NumberOfDays << ":"
        << Duration.NumberOfHours << ":"
        << Duration.NumberOfMinutes << ":"
        << Duration.NumberOfSeconds << "\n";
}

int main()
{
    int TotalSeconds = ReadPositiveNumber("Please Enter Total Seconds?");
    PrintTaskDurationDetails(SecondsToTaskDuration(TotalSeconds));
    return 0;
}
