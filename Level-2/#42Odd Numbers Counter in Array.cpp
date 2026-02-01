#include <iostream>
#include <cstdlib>
using namespace std;

// Program Name: Odd Numbers Counter in Array
// Purpose: Generates an array of random integers and counts how many odd numbers it contains.

enum OddEven { Odd, Even };

OddEven CheckOddEven(int Number) {
    if (Number % 2 == 0)
        return Even;
    return Odd;
}

int ReadPositiveNumber(string Message) {
    int Number;
    do {
        cout << Message;
        cin >> Number;
    } while (Number < 0);
    return Number;
}

int GenerateRandomNumber(int From, int To) {
    return rand() % (To - From + 1) + From;
}

void FillArray(int Arr[100], int Length) {
    for (int i = 0; i < Length; i++)
        Arr[i] = GenerateRandomNumber(1, 100);
}

int CountOddInArray(int Arr[100], int Length) {
    int Counter = 0;
    for (int i = 0; i < Length; i++)
        if (CheckOddEven(Arr[i]) == Odd)
            Counter++;
    return Counter;
}

void PrintArray(int Arr[100], int Length) {
    for (int i = 0; i < Length; i++)
        cout << Arr[i] << " ";
    cout << "\n";
}

int main() {
    srand((unsigned)time(NULL));
    
    int Arr[100];
    int Length = ReadPositiveNumber("Enter number of array elements: ");
    
    FillArray(Arr, Length);
    
    cout << "Array elements:\n";
    PrintArray(Arr, Length);

    int CountOddNumbers = CountOddInArray(Arr, Length);
    cout << "Number of odd numbers: " << CountOddNumbers << "\n";

    return 0;
}
