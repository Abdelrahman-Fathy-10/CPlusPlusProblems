#include <iostream>
#include <cmath>
using namespace std;

// Program Name: Custom Rounding Function
// Purpose: Reads a positive floating-point number from the user and rounds it
//          using a custom rounding function as well as the built-in C++ round function.

float ReadPositiveNumber(string Message) {
    float Number;
    cout << Message;
    cin >> Number;
    return Number;
}

float GetFraction(float Number) {
    return Number - int(Number);
}

float MyRound(float Number) {
    if (Number >= 0) {
        if (GetFraction(Number) >= 0.5)
            return int(Number) + 1;
        return int(Number);
    } else {
        if (GetFraction(-Number) >= 0.5)
            return int(Number) - 1;
        return int(Number);
    }
}

int main() {
    float Number = ReadPositiveNumber("Please enter a positive number: ");

    cout << "My Round Result: " << MyRound(Number) << endl;
    cout << "C++ Round Result: " << round(Number) << endl;

    return 0;
}
