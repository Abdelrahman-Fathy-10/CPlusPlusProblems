#include <iostream>   
#include <string>    
#include <cmath>   

using namespace std;  

/*Write a program to calculate rectangle area through diagonal and side area of 
rectangle and print it on the screen.
The use should enter:
a
d
Area = a * sqrt( d*d – a*a)
*/

void ReadNumbers(float& A, float& D)
{
    cout << "Please enter rectangle side A ? " << endl;
    cin >> A;

    cout << "Please enter rectangle diagonal D ? " << endl;
    cin >> D;
}
float RectangleAreaBySideAndDiagonal(float A, float D)
{
    float Area = A * sqrt(pow(D, 2) - pow(A, 2));

    return Area;  
}
void PrintResult(float Area)
{
    cout << "\nRectangle Area = " << Area << endl;
}

int main()
{
    float A, D; 
    ReadNumbers(A, D);
    PrintResult(RectangleAreaBySideAndDiagonal(A, D));
    return 0; 
}