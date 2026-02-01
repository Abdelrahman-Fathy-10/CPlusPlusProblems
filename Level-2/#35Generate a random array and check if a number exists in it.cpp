#include <iostream>
using namespace std;

// Program: Generate a random array and check if a number exists in it

int ReadNumber() {
    int Number;
    cout << "\nEnter a number to search for: ";
    cin >> Number;
    return Number;
}

int RandomNumber(int From, int To) {
    return rand() % (To - From + 1) + From;
}

void FillArrayWithRandomNumbers(int arr[100], int &arrLength) {
    cout << "\nEnter number of elements: ";
    cin >> arrLength;
    for (int i = 0; i < arrLength; i++)
        arr[i] = RandomNumber(1, 100);
}

void PrintArray(int arr[100], int arrLength) {
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

short FindNumberPositionInArray(int Number, int arr[100], int arrLength) {
    for (int i = 0; i < arrLength; i++)
        if (arr[i] == Number)
            return i;
    return -1;
}

bool IsNumberInArray(int Number, int arr[100], int arrLength) {
    return FindNumberPositionInArray(Number, arr, arrLength) != -1;
}

int main() {
    srand((unsigned)time(NULL));

    int arr[100];
    int arrLength;

    FillArrayWithRandomNumbers(arr, arrLength);

    cout << "\nArray elements:\n";
    PrintArray(arr, arrLength);

    int Number = ReadNumber();
    cout << "Searching for number: " << Number << "\n";

    if (!IsNumberInArray(Number, arr, arrLength))
        cout << "No, the number is not found :-(\n";
    else
        cout << "Yes, it is found :-)\n";

    return 0;
}
