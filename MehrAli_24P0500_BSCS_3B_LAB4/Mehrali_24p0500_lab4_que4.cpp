#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Stack
{
private:
    char arr[1000];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(char ch)
    {
        top++;
        arr[top] = ch;
    }

    char pop()
    {
        char ch = arr[top];
        top--;
        return ch;
    }
};

int main()
{
    string input;
    string clean;

    cout << "Enter a string: ";
    getline(cin, input);

    // Remove spaces and convert to lowercase
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] != ' ')
        {
            clean += tolower(input[i]);
        }
    }

    Stack s;

    // Push every character
    for (int i = 0; i < clean.length(); i++)
    {
        s.push(clean[i]);
    }

    bool palindrome = true;

    // Compare original with popped characters
    for (int i = 0; i < clean.length(); i++)
    {
        if (clean[i] != s.pop())
        {
            palindrome = false;
            break;
        }
    }

    if (palindrome)
    {
        cout << "Palindrome" << endl;
    }
    else
    {
        cout << "Not a Palindrome" << endl;
    }

    return 0;
}