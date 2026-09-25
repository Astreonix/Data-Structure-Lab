#include <iostream>
#include <string>
using namespace std;

class Stack
{
private:
    char arr[100];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(char value)
    {
        top++;
        arr[top] = value;
    }

    char pop()
    {
        char value = arr[top];
        top--;
        return value;
    }

    char peek()
    {
        return arr[top];
    }

    bool isEmpty()
    {
        return top == -1;
    }
};

bool isMatching(char open, char close)
{
    if (open == '(' && close == ')')
        return true;

    if (open == '[' && close == ']')
        return true;

    if (open == '{' && close == '}')
        return true;

    return false;
}

int main()
{
    string text;

    cout << "Enter brackets: ";
    getline(cin, text);

    Stack s;

    for (int i = 0; i < text.length(); i++)
    {
        char ch = text[i];

        if (ch == '(' || ch == '[' || ch == '{')
        {
            s.push(ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}')
        {
            if (s.isEmpty())
            {
                cout << "Not Balanced" << endl;
                cout << "First offending character index: " << i << endl;
                return 0;
            }

            char open = s.pop();

            if (!isMatching(open, ch))
            {
                cout << "Not Balanced" << endl;
                cout << "First offending character index: " << i << endl;
                return 0;
            }
        }
    }

    if (!s.isEmpty())
    {
        cout << "Not Balanced" << endl;

        cout << "First offending character index: ";

       
        Stack temp;
        string remaining;

        cout << "unmatched opening bracket" << endl;
    }
    else
    {
        cout << "Balanced" << endl;
    }

    return 0;
}