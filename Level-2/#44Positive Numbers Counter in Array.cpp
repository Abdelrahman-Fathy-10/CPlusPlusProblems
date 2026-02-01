#include <iostream>
#include <cstdlib>
using namespace std;

// Program Name: Positive Numbers Counter in Array
// Purpose: Generates an array of random integers in the range [-100, 100] and counts the positive numbers.

int RandomNumber(int From, int To) {
    return rand() % (To - From + 1) + From;
}

void FillArray(int arr[100], int &arrLength) {
    cout << "Enter number of elements: ";
    cin >> arrLength;
    for (int i = 0; i < arrLength; i++)
        arr[i] = RandomNumber(-100, 100);
}

void PrintArray(int arr[100], int arrLength) {
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int PositiveCount(int arr[100], int arrLength) {
    int Counter = 0;
    for (int i = 0; i < arrLength; i++)
        if (arr[i] >= 0)
            Counter++;
    return Counter;
}

int main() {
    srand((unsigned)time(NULL));
    
    int arr[100], arrLength;
    
    FillArray(arr, arrLength);
    
    cout << "Array Elements: ";
    PrintArray(arr, arrLength);
    
    cout << "Positive Numbers count: " << PositiveCount(arr, arrLength) << "\n";
    
    return 0;
}
