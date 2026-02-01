#include <iostream>
using namespace std;

// Program Name: Dynamic Array Input Program
// Purpose: Allows the user to input numbers into an array until they choose to stop, 
//          then displays the array length and its elements.

int ReadNumber() {
    int number;
    cout << "\nPlease enter a number: ";
    cin >> number;
    return number;
}

void AddArrayElement(int number, int arr[100], int &arrLength) {
    if (arrLength < 100) {
        arr[arrLength++] = number;  
    } else {
        cout << "Array is full! Cannot add more numbers.\n";
    }
}

void InputUserNumbersInArray(int arr[100], int &arrLength) {
    char choice;
    do {
        AddArrayElement(ReadNumber(), arr, arrLength);
        cout << "Do you want to add more numbers? [Y/N]: ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');
}

void PrintArray(int arr[100], int arrLength) {
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    int arr[100];
    int arrLength = 0;

    InputUserNumbersInArray(arr, arrLength);

    cout << "\nArray Length: " << arrLength << endl;
    cout << "Array elements: ";
    PrintArray(arr, arrLength);

    return 0;
}
