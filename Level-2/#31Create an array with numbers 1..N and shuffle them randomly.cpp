#include <iostream>
#include <cstdlib>
using namespace std;

// Program: Create an array with numbers 1..N and shuffle them randomly

int ReadPositiveNumber(string Message) {
    int Number;
    do {
        cout << Message;
        cin >> Number;
    } while (Number <= 0 || Number > 100);
    return Number;
}

int GenerateRandomNumber(int From, int To) {
    return rand() % (To - From + 1) + From;
}

void SwapNumbers(int &A, int &B) {
    int Temp = A;
    A = B;
    B = Temp;
}

void FillArrayWithSequence(int Arr[100], int Length) {
    for (int i = 0; i < Length; i++)
        Arr[i] = i + 1;
}

void ShuffleArray(int Arr[100], int Length) {
    for (int i = 0; i < Length; i++) {
        SwapNumbers(Arr[GenerateRandomNumber(1, Length) - 1],
                    Arr[GenerateRandomNumber(1, Length) - 1]);
    }
}

void PrintArray(int Arr[100], int Length) {
    for (int i = 0; i < Length; i++)
        cout << Arr[i] << " ";
    cout << "\n";
}

int main() {
    srand((unsigned)time(NULL));

    int Arr[100];
    int Length = ReadPositiveNumber("Please enter number of elements: ");

    FillArrayWithSequence(Arr, Length);
    cout << "\nArray elements: ";
    PrintArray(Arr, Length);

    ShuffleArray(Arr, Length);
    cout << "\nArray after shuffle: ";
    PrintArray(Arr, Length);

    return 0;
}
