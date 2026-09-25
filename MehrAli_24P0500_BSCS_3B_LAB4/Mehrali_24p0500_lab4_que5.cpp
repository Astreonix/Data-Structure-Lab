#include <iostream>
#include <string>
#include <cctype>
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

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;

    if (op == '*' || op == '/')
        return 2;

    return 0;
}

string infixToPostfix(string infix)
{
    Stack s;

    string postfix = "";

    for (int i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];

        // If number, directly add to postfix
        if (isdigit(ch))
        {
            postfix += ch;
        }

        // If opening bracket
        else if (ch == '(')
        {
            s.push(ch);
        }

        // If closing bracket
        else if (ch == ')')
        {
            while (!s.isEmpty() && s.peek() != '(')
            {
                postfix += s.pop();
            }

            if (!s.isEmpty())
                s.pop();
        }

        // If operator
        else
        {
            while (!s.isEmpty() &&
                   s.peek() != '(' &&
                   precedence(s.peek()) >= precedence(ch))
            {
                postfix += s.pop();
            }

            s.push(ch);
        }
    }

    // Pop remaining operators
    while (!s.isEmpty())
    {
        postfix += s.pop();
    }

    return postfix;
}