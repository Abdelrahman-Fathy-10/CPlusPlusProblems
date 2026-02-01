#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

// Program Name: Copy Prime Numbers from Array
// Purpose: Fills an array with random numbers and copies only the prime numbers into a second array.

enum PrimeNotPrime { Prime, NotPrime };

PrimeNotPrime CheckPrimeNumber(int Number) {
    if (Number < 2)
        return NotPrime;
    int limit = sqrt(Number);
    for (int i = 2; i <= limit; i++) {
        if (Number % i == 0)
            return NotPrime;
    }
    return Prime;
}

int GenerateRandomNumber(int From, int To) {
    return rand() % (To - From + 1) + From;
}

void AddArrayElement(int Number, int Arr[100], int& Length) {
    Arr[Length++] = Number;
}

void FillArray(int Arr[100], int& Length) {
    cout << "How many elements do you need in the array?: ";
    cin >> Length;
    for (int i = 0; i < Length; i++)
        Arr[i] = GenerateRandomNumber(1, 100);
}

void CopyArray(int ArrSource[100], int ArrDest[100], int SrcLength, int& DestLength) {
    for (int i = 0; i < SrcLength; i++)
        if (CheckPrimeNumber(ArrSource[i]) == Prime)
            AddArrayElement(ArrSource[i], ArrDest, DestLength);
}

void PrintArray(int Arr[100], int Length) {
    for (int i = 0; i < Length; i++)
        cout << Arr[i] << " ";
    cout << "\n";
}

int main() {
    srand((unsigned)time(NULL));

    int Arr[100], Length = 0;
    int Arr2[100], Length2 = 0;

    FillArray(Arr, Length);
    cout << "Original Array Elements:\n";
    PrintArray(Arr, Length);

    CopyArray(Arr, Arr2, Length, Length2);
    cout << "After copy (prime numbers only):\n";
    PrintArray(Arr2, Length2);

    return 0;
}
