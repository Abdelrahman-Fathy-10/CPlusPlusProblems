#include <iostream>
#include <string>

using namespace std;

/*Write a program to calculate the task duration in seconds and print it on screen
Given the time duration of a task in the number of days, hours, minutes, and seconds,*/

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

TaskDuration ReadTaskDuration()
{
    TaskDuration Duration;

    Duration.NumberOfDays = ReadPositiveNumber("Please Enter Number Of Days?");
    Duration.NumberOfHours = ReadPositiveNumber("Please Enter Number Of Hours?");
    Duration.NumberOfMinutes = ReadPositiveNumber("Please Enter Number Of Minutes?");
    Duration.NumberOfSeconds = ReadPositiveNumber("Please Enter Number Of Seconds?");

    return Duration;
}

int TaskDurationInSeconds(TaskDuration Duration)
{
    int TotalSeconds = 0;

    TotalSeconds = Duration.NumberOfDays * 24 * 60 * 60;
    TotalSeconds += Duration.NumberOfHours * 60 * 60;
    TotalSeconds += Duration.NumberOfMinutes * 60;
    TotalSeconds += Duration.NumberOfSeconds;

    return TotalSeconds;
}

int main()
{
    cout << "\nTask Duration In Seconds: "
        << TaskDurationInSeconds(ReadTaskDuration()) << endl;

    return 0;
}