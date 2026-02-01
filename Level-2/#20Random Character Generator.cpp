// Program Name: Random Character Generator
// Description : Generates a random character of a specific type: lowercase, uppercase, digit, or special character.

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

enum Letters { SmallLetters, CapitalLetters, Digit, SpecialChar };

// Returns a random integer in the range [From, To]
int RandomNumber(int From, int To) {
    return rand() % (To - From + 1) + From;
}

// Returns a random character based on the specified LetterType
char GetLetterType(Letters LetterType) {
    switch (LetterType) {
    case SmallLetters:
        return char(RandomNumber(97, 122));   // a-z
    case CapitalLetters:
        return char(RandomNumber(65, 90));    // A-Z
    case SpecialChar:
        return char(RandomNumber(33, 47));    // ! " # $ % & ' ( ) * + , - . /
    case Digit:
        return char(RandomNumber(48, 57));    // 0-9
    default:
        return '\0';
    }
}

int main()
{
    srand((unsigned)time(NULL));

    cout << "Random lowercase letter : " << GetLetterType(SmallLetters) << endl;
    cout << "Random uppercase letter : " << GetLetterType(CapitalLetters) << endl;
    cout << "Random special character : " << GetLetterType(SpecialChar) << endl;
    cout << "Random digit : " << GetLetterType(Digit) << endl;

    return 0;
}
