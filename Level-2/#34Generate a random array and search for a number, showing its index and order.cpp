#include <iostream>
using namespace std;

// Program: Generate a random array and search for a number, showing its index and order

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

int ReadNumber() {
    int Number;
    cout << "\nEnter a number to search for: ";
    cin >> Number;
    return Number;
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

    short pos = FindNumberPositionInArray(Number, arr, arrLength);

    if (pos == -1)
        cout << "Number not found :-(\n";
    else {
        cout << "Number found at index: " << pos << "\n";
        cout << "Number order in array: " << pos + 1 << "\n";
    }

    return 0;
}
