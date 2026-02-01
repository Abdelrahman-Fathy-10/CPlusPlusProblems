// Program Name: Three-Letter Password Guesser
// Description : Prompts the user for a 3-uppercase-letter password and tries all possible combinations to find it.

#include <iostream>
#include <string>

using namespace std;

string ReadPassword() {
    string Password;
    cout << "Please enter your password (three capital letters): ";
    cin >> Password;
    return Password;
}

bool GuessPassword(string OriginalPassword) {
    string Word;
    int Counter = 0;
    for (int i = 65; i <= 90; i++) {
        for (int j = 65; j <= 90; j++) {
            for (int k = 65; k <= 90; k++) {
                Word = char(i);
                Word += char(j);
                Word += char(k);
                Counter++;
                cout << "Trial [" << Counter << "] " << Word << endl;
                if (Word == OriginalPassword) {
                    cout << "\nPassword is: " << Word << endl;
                    cout << "Found in trial " << Counter << endl;
                    return true;
                }
                Word = "";
            }
        }
    }
    return false;
}

int main()
{
    GuessPassword(ReadPassword());
    return 0;
}
