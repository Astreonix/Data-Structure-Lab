#include <iostream>
#include <string>
using namespace std;

const int CAPACITY = 8;

class CircularQueue
{
private:
    string data[CAPACITY];
    int frontIndex;
    int rearIndex;
    int count;

public:
    CircularQueue()
    {
        frontIndex = 0;
        rearIndex = 0;
        count = 0;
    }

    bool isEmpty()
    {
        return count == 0;
    }

    bool isFull()
    {
        return count == CAPACITY;
    }

    int size()
    {
        return count;
    }

    void enqueue(string value)
    {
        if (isFull())
        {
            cout << "Overflow: queue is full, cannot add \"" << value << "\"" << endl;
            return;
        }
        data[rearIndex] = value;
        rearIndex = (rearIndex + 1) % CAPACITY;
        count++;
        cout << "\"" << value << "\" added to the queue." << endl;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Underflow: queue is empty, nothing to remove." << endl;
            return;
        }
        string removed = data[frontIndex];
        frontIndex = (frontIndex + 1) % CAPACITY;
        count--;
        cout << "\"" << removed << "\" removed from the queue." << endl;
    }

    void showFront()
    {
        if (isEmpty())
        {
            cout << "Queue is empty, no front element." << endl;
            return;
        }
        cout << "Front element: " << data[frontIndex] << endl;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Front -> ";
        for (int i = 0; i < count; i++)
        {
            int index = (frontIndex + i) % CAPACITY;
            cout << data[index] << " ";
        }
        cout << "<- Rear" << endl;
    }
};

int main()
{
    CircularQueue q;
    int choice;
    string value;

    do
    {
        cout << endl;
        cout << "===== Circular Queue Menu =====" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Front" << endl;
        cout << "4. Size" << endl;
        cout << "5. Display" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter a string: ";
            cin >> value;
            q.enqueue(value);
        }
        else if (choice == 2)
        {
            q.dequeue();
        }
        else if (choice == 3)
        {
            q.showFront();
        }
        else if (choice == 4)
        {
            cout << "Current size: " << q.size() << endl;
        }
        else if (choice == 5)
        {
            q.display();
        }
        else if (choice == 6)
        {
            cout << "Exiting program." << endl;
        }
        else
        {
            cout << "Invalid choice, try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
