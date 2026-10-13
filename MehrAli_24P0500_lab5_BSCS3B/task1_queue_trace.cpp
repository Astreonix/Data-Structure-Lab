#include <iostream>
using namespace std;

int arr[20];
int frontIndex = 0;
int rearIndex = -1;

void show(string op)
{
    cout << op << endl;
    if (rearIndex < frontIndex)
    {
        cout << "Queue: [empty]" << endl;
    }
    else
    {
        cout << "Queue: Front -> ";
        for (int i = frontIndex; i <= rearIndex; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "<- Rear" << endl;
        cout << "Front = " << arr[frontIndex] << ", Rear = " << arr[rearIndex] << endl;
    }
    cout << endl;
}

void enqueue(int x)
{
    rearIndex++;
    arr[rearIndex] = x;
    show("enqueue(" + to_string(x) + ")");
}

void dequeue()
{
    if (rearIndex < frontIndex)
    {
        cout << "Underflow" << endl;
        return;
    }
    int removed = arr[frontIndex];
    frontIndex++;
    show("dequeue() -> removed " + to_string(removed));
}

int main()
{
    enqueue(12);
    enqueue(7);
    enqueue(25);
    dequeue();
    dequeue();
    enqueue(9);
    enqueue(30);
    dequeue();

    cout << "Items leave in the same order they arrived (FIFO)." << endl;
    return 0;
}
