// Program Name: Random Key Generator
// Description : Generates a specified number of random keys composed of uppercase letters.

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Enumeration: enCharType
// Purpose: Defines character types for generating random characters.
enum enCharType { SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4 };

// Generates a random integer in the range [From, To]
int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

// Returns a random character based on the specified type
char GetRandomCharacter(enCharType CharType)
{
    switch (CharType)
    {
        case SmallLetter:      return char(RandomNumber(97, 122));   // a-z
        case CapitalLetter:    return char(RandomNumber(65, 90));    // A-Z
        case SpecialCharacter: return char(RandomNumber(33, 47));    // ! " # $ % & ' ( ) * + , - . /
        case Digit:            return char(RandomNumber(48, 57));    // 0-9
        default:               return '\0';
    }
}

// Prompts the user to enter a positive number
int ReadPositiveNumber(string Message)
{
    int Number = 0;
    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}

// Generates a word of specified length and character type
string GenerateWord(enCharType CharType, short Length)
{
    string Word;
    for (int i = 1; i <= Length; i++)
        Word += GetRandomCharacter(CharType);
    return Word;
}

// Generates a single key in the format XXXX-XXXX-XXXX-XXXX
string GenerateKey()
{
    return GenerateWord(CapitalLetter, 4) + "-" +
           GenerateWord(CapitalLetter, 4) + "-" +
           GenerateWord(CapitalLetter, 4) + "-" +
           GenerateWord(CapitalLetter, 4);
}

// Generates and prints multiple keys
void GenerateKeys(short NumberOfKeys)
{
    for (int i = 1; i <= NumberOfKeys; i++)
        cout << "Key [" << i << "] : " << GenerateKey() << endl;
}

int main()
{
    srand((unsigned)time(NULL)); // Seed random generator
    GenerateKeys(ReadPositiveNumber("Please enter how many keys to generate?"));
    return 0;
}
