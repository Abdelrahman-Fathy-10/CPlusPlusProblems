#include <iostream>  
#include <string>     
using namespace std; 


//Write a program to ask the use to enter his / her name and print it on screen.


string ReadName()
{
    string Name; 

    cout << "Please enter your name? " << endl;
    getline(cin, Name);

    return Name; 
}


void PrintName(string Name)
{
    cout << "\n Your Name is: " << Name << endl;
}

int main()
{
    PrintName(ReadName());
    return 0; 
}