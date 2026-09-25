#include <iostream>
using namespace std;

class Stack
{
private:
    int arr[10];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(int value)
    {
        if (isFull())
        {
            cout << "Stack Overflow! Stack is full." << endl;
        }
        else
        {
            top++;
            arr[top] = value;
            cout << value << " pushed into stack." << endl;
        }
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow! Stack is empty." << endl;
        }
        else
        {
            cout << arr[top] << " popped from stack." << endl;
            top--;
        }
    }

    void peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty." << endl;
        }
        else
        {
            cout << "Top element: " << arr[top] << endl;
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty." << endl;
        }
        else
        {
            cout << "Stack elements: ";

            for (int i = top; i >= 0; i--)
            {
                cout << arr[i] << " ";
            }

            cout << endl;
        }
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == 9;
    }
};

int main()
{
    Stack s;

    int choice;
    int value;

    do
    {
        cout << "\n===== STACK MENU =====" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. isEmpty" << endl;
        cout << "6. isFull" << endl;
        cout << "7. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            s.push(value);
            break;

        case 2:
            s.pop();
            break;

        case 3:
            s.peek();
            break;

        case 4:
            s.display();
            break;

        case 5:
            if (s.isEmpty())
                cout << "Stack is Empty." << endl;
            else
                cout << "Stack is NOT Empty." << endl;
            break;

        case 6:
            if (s.isFull())
                cout << "Stack is Full." << endl;
            else
                cout << "Stack is NOT Full." << endl;
            break;

        case 7:
            cout << "Program ended." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 7);

    return 0;
}