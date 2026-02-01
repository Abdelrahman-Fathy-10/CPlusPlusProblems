#include <iostream>
#include <string>    
using namespace std;  

/*Write a program to ask the user to enter :
• Age
If age is between 18 and 45 print “Valid Age” otherwise print 
“Invalid Age” and re-ask user to enter a valid age.
Note: You should keep asking user to enter a valid age until 
s/she enters it*/

int ReadAge()
{
    int Age; 

    cout << "Please enter an Age between 18 and 45 ? " << endl;
    cin >> Age;

    return Age;  
}
bool ValidateNumberInRange(int Number, int From, int To)
{
    return (Number >= From && Number <= To);
}
int ReadUntilAgeBetween(int From, int To)
{
    int Age = 0; 
    do
    {
        Age = ReadAge();

    } while (!ValidateNumberInRange(Age, From, To)); 

    return Age;  
}
void PrintResult(int Age)
{
    cout << "Your Age is: " << Age << endl;
}
int main()
{
    PrintResult(ReadUntilAgeBetween(18, 45));
    return 0; 
}