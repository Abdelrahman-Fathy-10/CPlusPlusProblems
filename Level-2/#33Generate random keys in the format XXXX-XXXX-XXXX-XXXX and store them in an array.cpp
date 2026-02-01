#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

// Program: Generate random keys in the format XXXX-XXXX-XXXX-XXXX and store them in an array

enum enCharType { 
    SmallLetter = 1,   // Lowercase letters a-z
    CapitalLetter = 2, // Uppercase letters A-Z
    SpecialCharacter = 3, // Special characters ! " # $ % & ' ( ) * + , - . / 
    Digit = 4          // Digits 0-9
};

int RandomNumber(int From, int To) {
    return rand() % (To - From + 1) + From;
}

char GetRandomCharacter(enCharType CharType) {
    switch (CharType) {
        case SmallLetter:      return char(RandomNumber(97, 122));
        case CapitalLetter:    return char(RandomNumber(65, 90));
        case SpecialCharacter: return char(RandomNumber(33, 47));
        case Digit:            return char(RandomNumber(48, 57));
    }
    return '\0';
}

string GenerateWord(enCharType CharType, short Length) {
    string Word = "";
    for (int i = 0; i < Length; i++)
        Word += GetRandomCharacter(CharType);
    return Word;
}

string GenerateKey() {
    // Format: XXXX-XXXX-XXXX-XXXX (uppercase letters only)
    return GenerateWord(CapitalLetter, 4) + "-" +
           GenerateWord(CapitalLetter, 4) + "-" +
           GenerateWord(CapitalLetter, 4) + "-" +
           GenerateWord(CapitalLetter, 4);
}

void FillArrayWithKeys(string arr[100], int arrLength) {
    for (int i = 0; i < arrLength; i++)
        arr[i] = GenerateKey();
}

void PrintStringArray(string arr[100], int arrLength) {
    cout << "\nGenerated Keys:\n";
    for (int i = 0; i < arrLength; i++)
        cout << "Key[" << i << "] : " << arr[i] << "\n";
    cout << "\n";
}

int ReadPositiveNumber(string Message) {
    int Number = 0;
    do {
        cout << Message;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}

int main() {
    srand((unsigned)time(NULL));

    string arr[100];
    int arrLength = ReadPositiveNumber("How many keys do you want to generate? ");

    FillArrayWithKeys(arr, arrLength);
    PrintStringArray(arr, arrLength);

    return 0;
}
