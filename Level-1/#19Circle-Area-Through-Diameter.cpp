#include <iostream> 
#include <string>   
#include <cmath>   
using namespace std;

/*Write a program to calculate circle area through diameter, then print it on the screen.
The use should enter:
D*/

float ReadDiameter()
{
    float D;

    cout << "Please enter diameter D ? " << endl;
    cin >> D;

    return D;
}

float CircleAreaByDiameter(float D)
{
    const float PI = 3.141592653589793238;

    float Area = (pow(D, 2) * PI) / 4;

    return Area;
}

void PrintResult(float Area)
{
    cout << "\nCircle Area = " << Area << endl;
}

int main()
{
    PrintResult(CircleAreaByDiameter(ReadDiameter()));

    return 0;
}