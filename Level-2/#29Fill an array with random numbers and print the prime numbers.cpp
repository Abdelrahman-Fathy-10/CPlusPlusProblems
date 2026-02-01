#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

// Program: Fill an array with random numbers and print the prime numbers

enum PrimeNotPrime { Prime, NotPrime };

int ReadPositiveNumber(string Message) {
    int Number;
    do {
        cout << Message;
        cin >> Number;
    } while (Number < 0 || Number > 100);
    return Number;
}

int GenerateRandomNumber(int From, int To) {
    return rand() % (To - From + 1) + From;
}

PrimeNotPrime CheckPrimeNotPrime(int Number) {
    if (Number < 2) return NotPrime;
    for (int Counter = 2; Counter <= sqrt(Number); Counter++) {
        if (Number % Counter == 0) return NotPrime;
    }
    return Prime;
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

void PrintArrayPrimeNumbers(int Arr[100], int Length) {
    for (int i = 0; i < Length; i++) {
        if (CheckPrimeNotPrime(Arr[i]) == Prime)
            cout << Arr[i] << " ";
    }
    cout << "\n";
}

int main() {
    srand((unsigned)time(NULL));

    int Arr[100];
    int Length = ReadPositiveNumber("Please enter number of elements: ");
    FillRandomArrayData(Arr, Length);

    cout << "\nArray elements: ";
    PrintArrayData(Arr, Length);

    cout << "\nPrime numbers in the array: ";
    PrintArrayPrimeNumbers(Arr, Length);

    return 0;
}
