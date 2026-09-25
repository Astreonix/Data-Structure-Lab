#include <iostream>
using namespace std;

class Stack
{
private:
    struct Node
    {
        int data;
        Node* next;
    };

    Node* top;

public:
    Stack()
    {
        top = NULL;
    }

    void push(int value)
    {
        Node* newNode = new Node;

        newNode->data = value;
        newNode->next = top;

        top = newNode;

        cout << value << " pushed into stack." << endl;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow! Stack is empty." << endl;
            return;
        }

        Node* temp = top;

        cout << temp->data << " popped from stack." << endl;

        top = top->next;

        delete temp;
    }

    void peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty." << endl;
        }
        else
        {
            cout << "Top element: " << top->data << endl;
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty." << endl;
            return;
        }

        Node* temp = top;

        cout << "Stack elements: ";

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    bool isEmpty()
    {
        return top == NULL;
    }

    ~Stack()
    {
        while (top != NULL)
        {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main()
{
    Stack s;

    int choice;
    int value;

    do
    {
        cout << "\n===== LINKED LIST STACK =====" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. isEmpty" << endl;
        cout << "6. Exit" << endl;

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
            cout << "Program ended." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 6);

    return 0;
}