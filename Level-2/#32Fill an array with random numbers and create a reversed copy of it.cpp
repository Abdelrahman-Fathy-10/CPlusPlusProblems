#include <iostream>
#include <cstdlib>
using namespace std;

// Program: Fill an array with random numbers and create a reversed copy of it

int RandomNumber(int From, int To) {
    return rand() % (To - From + 1) + From;
}

void FillArrayWithRandomNumbers(int arr[100], int &arrLength) {
    cout << "Enter number of elements: ";
    cin >> arrLength;
    for (int i = 0; i < arrLength; i++)
        arr[i] = RandomNumber(1, 100);
}

void PrintArray(int arr[100], int arrLength) {
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

void CopyArrayInReverse(int arrSource[100], int arrDestination[100], int arrLength) {
    for (int i = 0; i < arrLength; i++)
        arrDestination[i] = arrSource[arrLength - 1 - i];
}

int main() {
    srand((unsigned)time(NULL));

    int arr[100], arrLength;
    FillArrayWithRandomNumbers(arr, arrLength);

    int arr2[100];
    CopyArrayInReverse(arr, arr2, arrLength);

    cout << "\nOriginal array:\n";
    PrintArray(arr, arrLength);

    cout << "\nReversed array:\n";
    PrintArray(arr2, arrLength);

    return 0;
}
