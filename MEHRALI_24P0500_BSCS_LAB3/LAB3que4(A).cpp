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

Node* mergeLists(Node* A, Node* B)
{
    // If A is empty
    if (A == nullptr)
        return B;

    // If B is empty
    if (B == nullptr)
        return A;

    Node* head = nullptr;
    Node* tail = nullptr;

    // Choose first node
    if (A->data <= B->data)
    {
        head = A;
        A = A->next;
    }
    else
    {
        head = B;
        B = B->next;
    }

    tail = head;

    // Merge while both lists have nodes
    while (A != nullptr && B != nullptr)
    {
        if (A->data <= B->data)
        {
            tail->next = A;
            A = A->next;
        }
        else
        {
            tail->next = B;
            B = B->next;
        }

        tail = tail->next;
    }

    // Attach remaining nodes
    if (A != nullptr)
    {
        tail->next = A;
    }
    else
    {
        tail->next = B;
    }

    return head;
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

    // Build A
    for (int i = 0; i < N; i++)
    {
        int value;
        cin >> value;

        insertEnd(A, value);
    }

    // Build B
    for (int i = 0; i < M; i++)
    {
        int value;
        cin >> value;

        insertEnd(B, value);
    }

    Node* merged = mergeLists(A, B);

    printList(merged);

    deleteList(merged);

    return 0;
}