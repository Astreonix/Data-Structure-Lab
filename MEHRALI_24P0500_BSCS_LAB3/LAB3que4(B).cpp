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

Node* mergeRecursive(Node* A, Node* B)
{
    // A is empty
    if (A == nullptr)
        return B;

    // B is empty
    if (B == nullptr)
        return A;

    if (A->data <= B->data)
    {
        A->next = mergeRecursive(A->next, B);

        return A;
    }
    else
    {
        B->next = mergeRecursive(A, B->next);

        return B;
    }
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
    int N, M;
    cin >> N >> M;

    Node* A = nullptr;
    Node* B = nullptr;

    for (int i = 0; i < N; i++)
    {
        int value;
        cin >> value;

        insertEnd(A, value);
    }

    for (int i = 0; i < M; i++)
    {
        int value;
        cin >> value;

        insertEnd(B, value);
    }

    Node* merged = mergeRecursive(A, B);

    printList(merged);

    deleteList(merged);

    return 0;
}#include <iostream>
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

Node* mergeRecursive(Node* A, Node* B)
{
    // A is empty
    if (A == nullptr)
        return B;

    // B is empty
    if (B == nullptr)
        return A;

    if (A->data <= B->data)
    {
        A->next = mergeRecursive(A->next, B);

        return A;
    }
    else
    {
        B->next = mergeRecursive(A, B->next);

        return B;
    }
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
    int N, M;
    cin >> N >> M;

    Node* A = nullptr;
    Node* B = nullptr;

    for (int i = 0; i < N; i++)
    {
        int value;
        cin >> value;

        insertEnd(A, value);
    }

    for (int i = 0; i < M; i++)
    {
        int value;
        cin >> value;

        insertEnd(B, value);
    }

    Node* merged = mergeRecursive(A, B);

    printList(merged);

    deleteList(merged);

    return 0;
}