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

Node* createCircle(int n)
{
    if (n <= 0)
        return nullptr;

    Node* head = new Node(1);
    Node* tail = head;

    for (int i = 2; i <= n; i++)
    {
        Node* newNode = new Node(i);

        tail->next = newNode;
        tail = newNode;
    }

    // Make the list circular
    tail->next = head;

    return head;
}

int josephus(int n, long long k)
{
    Node* head = createCircle(n);

    // Only one player
    if (n == 1)
    {
        int answer = head->data;
        delete head;

        return answer;
    }

    Node* current = head;
    int remaining = n;

    while (remaining > 1)
    {
        // Move K-1 times
        for (long long i = 1; i < k; i++)
        {
            current = current->next;
        }

        // The next node is eliminated
        Node* eliminated = current->next;

        // Remove it from circle
        current->next = eliminated->next;

        // Continue from next player
        current = current->next;

        delete eliminated;

        remaining--;
    }

    int answer = current->data;

    delete current;

    return answer;
}

int main()
{
    int T;
    cin >> T;

    for (int test = 1; test <= T; test++)
    {
        int N;
        long long K;

        cin >> N >> K;

        int answer = josephus(N, K);

        cout << "Case " << test << ": " << answer << endl;
    }

    return 0;
}