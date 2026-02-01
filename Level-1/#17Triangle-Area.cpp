#include <iostream>
#include <string>    
using namespace std;

/*Write a program to calculate triangle area then print it on the screen.
The use should enter:
a
h*/

void ReadNumbers(float& A, float& H)
{
    cout << "Please enter triangle base A ? " << endl;
    cin >> A;

    cout << "Please enter triangle height H ? " << endl;
    cin >> H;
}
float TriangleArea(float A, float H)
{
    float Area = (A / 2) * H;

    return Area;
}
void PrintResult(float Area)
{
    cout << "\nTriangle Area = " << Area << endl;
}

int main()
{
    float A, H;  
    ReadNumbers(A, H);
    PrintResult(TriangleArea(A, H));
    return 0; 
}