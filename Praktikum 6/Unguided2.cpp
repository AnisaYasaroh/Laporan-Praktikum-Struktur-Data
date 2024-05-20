#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    string input;
    cout << "Masukkan Kalimat : ";
    getline(cin, input);

    stack<char> charStack;
    int lengthInput = input.length();

    for (int a_63 = 0; a_63 < lengthInput; a_63++)
    {
        charStack.push(input[a_63]);
    }

    for (int a_63 = 0; a_63 < lengthInput; a_63++)
    {
        cout << charStack.top();
        charStack.pop();
    }

    return 0;
}