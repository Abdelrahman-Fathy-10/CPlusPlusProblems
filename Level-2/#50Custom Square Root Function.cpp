#include <iostream>
#include <cmath>
using namespace std;

// Program Name: Custom Square Root Function
// Purpose: Computes the square root of a non-negative number using binary search 
//          and compares results with standard expectations. Returns NAN for negative inputs.

double my_sqrt(double x) {
    if (x < 0) {
        return NAN;
    }

    double left = 0, right = x + 1;
    for (int i = 0; i < 20; i++) {
        double middle = (left + right) / 2;
        if (middle * middle < x) {
            left = middle;
        } else {
            right = middle;
        }
    }

    return left;
}

int main() {
    cout << "my_sqrt(4) = " << my_sqrt(4) << endl;
    cout << "my_sqrt(1024) = " << my_sqrt(1024) << endl;
    cout << "my_sqrt(2) = " << my_sqrt(2) << endl;
    cout << "my_sqrt(0) = " << my_sqrt(0) << endl;
    cout << "my_sqrt(0.25) = " << my_sqrt(0.25) << endl;
    cout << "my_sqrt(-2) = " << my_sqrt(-2) << endl;

    return 0;
}
