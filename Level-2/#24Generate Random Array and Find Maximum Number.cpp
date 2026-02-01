#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Program: Generate Random Array and Find Maximum Number

int ReadPositiveNumber(string Message) {
    int Number;
    do {
        cout << Message;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}

int GenerateRandomNumber(int From, int To) {
    return rand() % (To - From + 1) + From;
}

int MaxNumberInArray(int Arr[100], int Length) {
    int Max = Arr[0];
    for (int i = 1; i < Length; i++) {
        if (Arr[i] > Max)
            Max = Arr[i];
    }
    return Max;
}

void FillRandomArrayData(int Arr[100], int Length) {
    for (int i = 0; i < Length; i++)
        Arr[i] = GenerateRandomNumber(1, 100);
}

void PrintArrayData(int Arr[100], int Length) {
    for (int i = 0; i < Length; i++)
        cout << Arr[i] << " ";
    cout << "\n";
}

int main() {
    srand((unsigned)time(NULL));

    int Arr[100];
    int Length = ReadPositiveNumber("Please enter number of elements: ");

    FillRandomArrayData(Arr, Length);

    cout << "Array elements: ";
    PrintArrayData(Arr, Length);

    cout << "Max number is " << MaxNumberInArray(Arr, Length) << "\n";

    return 0;
}
