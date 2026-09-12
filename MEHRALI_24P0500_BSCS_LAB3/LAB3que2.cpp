#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

void insertEnd(Node*& head, int value)
{
    Node* newNode = new Node(value);

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void insertAtPosition(Node*& head, int x, int p)
{
    Node* newNode = new Node(x);

    // Insert at beginning
    if (p <= 1 || head == nullptr)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;

    // Go to position before P
    for (int i = 1; i < p - 1 && temp->next != nullptr; i++)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteFirst(Node*& head, int x)
{
    if (head == nullptr)
        return;

    // Delete head
    if (head->data == x)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* prev = head;
    Node* current = head->next;

    while (current != nullptr)
    {
        if (current->data == x)
        {
            prev->next = current->next;
            delete current;
            return;
        }

        prev = current;
        current = current->next;
    }
}

void reverseList(Node*& head)
{
    Node* previous = nullptr;
    Node* current = head;

    while (current != nullptr)
    {
        Node* nextNode = current->next;

        current->next = previous;

        previous = current;
        current = nextNode;
    }

    head = previous;
}

void printList(Node* head)
{
    if (head == nullptr)
    {
        cout << "EMPTY" << endl;
        return;
    }

    Node* temp = head;

    while (temp != nullptr)
    {
        cout << temp->data;

        if (temp->next != nullptr)
            cout << " ";

        temp = temp->next;
    }

    cout << endl;
}

void deleteList(Node*& head)
{
    while (head != nullptr)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main()
{
    int N;
    cin >> N;

    Node* head = nullptr;

    for (int i = 0; i < N; i++)
    {
        int value;
        cin >> value;

        insertEnd(head, value);
    }

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++)
    {
        char operation;
        cin >> operation;

        if (operation == 'I')
        {
            int X, P;
            cin >> X >> P;

            insertAtPosition(head, X, P);
        }
        else if (operation == 'D')
        {
            int X;
            cin >> X;

            deleteFirst(head, X);
        }
        else if (operation == 'R')
        {
            reverseList(head);
        }
    }

    printList(head);

    deleteList(head);

    return 0;
}