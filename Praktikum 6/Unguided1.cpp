#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isPalindrome(const string& input) {
    stack<char> charStack;
    int lengthInput = input.length();

    for (int i = 0; i < lengthInput; i++) {
        charStack.push(input[i]);
    }

    for (int i = 0; i < lengthInput; i++) {
        if (input[i] != charStack.top()) {
            return false;
        }
        charStack.pop();
    }

    return true;
}

int main() {
    string input;
    char choice;

    do {
        cout << "\nMasukkan Kalimat: ";
        cin >> input;

        if (isPalindrome(input)) {
            cout << "Kalimat " << input <<  " adalah palindrom" << endl;
        } else {
            cout << "Kalimat " << input << " bukan palindrom" << endl;
        }

        cout << "Lanjutkan? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
