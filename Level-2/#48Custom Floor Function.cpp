#include <iostream>
#include <cmath>
using namespace std;

// Program Name: Custom Floor Function
// Purpose: Reads a floating-point number from the user and computes its floor value
//          using a custom function and compares it with C++ built-in floor function.

int MyFloor(float Number) {
    if (Number > 0)
        return int(Number);
    else
        return int(Number) - 1;
}

float ReadNumber() {
    float Number;
    cout << "Please enter a number: ";
    cin >> Number;
    return Number;
}

int main() {
    float Number = ReadNumber();

    cout << "My MyFloor Result : " << MyFloor(Number) << endl;
    cout << "C++ floor Result  : " << floor(Number) << endl;

    return 0;
}
