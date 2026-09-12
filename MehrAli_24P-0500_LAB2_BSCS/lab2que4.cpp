#include <iostream>
using namespace std;

class SupplyList
{
private:
    static const int MAX = 100;

    int supplies[MAX];
    int size;

public:

  
    SupplyList()
    {
        size = 0;
    }

    void addAtEnd(int code)
    {
        if (size == MAX)
        {
            cout << "List is full. Cannot add supply code.\n";
            return;
        }

        supplies[size] = code;
        size++;

        cout << "Supply code added successfully.\n";
    }


    void insertAtPosition(int code, int position)
    {
        if (size == MAX)
        {
            cout << "List is full. Cannot insert supply code.";
            return;
        }

        if (position < 1 || position > size + 1)
        {
            cout << "Invalid position.\n";
            return;
        }


        for (int i = size; i >= position; i--)
        {
            supplies[i] = supplies[i - 1];
        }

        supplies[position - 1] = code;
        size++;

        cout << "Supply code inserted successfully.";
    }

    void removeAtPosition(int position)
    {
        if (size == 0)
        {
            cout << "List is empty. Nothing to remove.";
            return;
        }

        if (position < 1 || position > size)
        {
            cout << "Invalid position.\n";
            return;
        }
        for (int i = position - 1; i < size - 1; i++)
        {
            supplies[i] = supplies[i + 1];
        }

        size--;

        cout << "Supply code removed successfully.";
    }


    void removeAll(int code)
    {
        if (size == 0)
        {
            cout << "List is empty. Nothing to remove.";
            return;
        }

        int newSize = 0;
        int removedCount = 0;


        for (int i = 0; i < size; i++)
        {
            if (supplies[i] != code)
            {
                supplies[newSize] = supplies[i];
                newSize++;
            }
            else
            {
                removedCount++;
            }
        }

        size = newSize;

        if (removedCount == 0)
        {
            cout << "Supply code not found.";
        }
        else
        {
            cout << removedCount
                 << " occurrence(s) of supply code removed.";
        }
    }

    void searchAll(int code)
    {
        if (size == 0)
        {
            cout << "List is empty.";
            return;
        }

        bool found = false;

        cout << "Supply code found at position(s): ";

        for (int i = 0; i < size; i++)
        {
            if (supplies[i] == code)
            {
                cout << i + 1 << " ";
                found = true;
            }
        }

        if (!found)
        {
            cout << "none";
        }

        cout << endl;
    }

    void display()
    {
        if (size == 0)
        {
            cout << "List is empty.";
            return;
        }

        cout << "Supply codes: ";

        for (int i = 0; i < size; i++)
        {
            cout << supplies[i] << " ";
        }

        cout << endl;
    }
    void reverseList()
    {
        if (size == 0)
        {
            cout << "List is empty. Nothing to reverse.";
            return;
        }

        int start = 0;
        int end = size - 1;

        while (start < end)
        {
            int temp = supplies[start];
            supplies[start] = supplies[end];
            supplies[end] = temp;

            start++;
            end--;
        }

        cout << "List reversed successfully.";
    }

    void showSizeAndCapacity()
    {
        cout << "Current size: " << size << endl;
        cout << "Maximum capacity: " << MAX << endl;
    }

    void clearList()
    {
        size = 0;

        cout << "List cleared successfully.";
    }
};


int main()
{
    SupplyList supplies;

    int choice;
    int code;
    int position;

    do
    {
        cout << "========== EMERGENCY SUPPLY DISTRIBUTION LIST ==========";
        cout << "1. Add supply code at end\n";
        cout << "2. Insert supply code at position\n";
        cout << "3. Remove supply code from position\n";
        cout << "4. Remove all occurrences of supply code\n";
        cout << "5. Search supply code\n";
        cout << "6. Display supply codes\n";
        cout << "7. Reverse list\n";
        cout << "8. Display size and capacity\n";
        cout << "9. Clear list\n";
        cout << "10. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter supply code: ";
            cin >> code;

            supplies.addAtEnd(code);
            break;

        case 2:
            cout << "Enter supply code: ";
            cin >> code;

            cout << "Enter position: ";
            cin >> position;

            supplies.insertAtPosition(code, position);
            break;

        case 3:
            cout << "Enter position to remove: ";
            cin >> position;

            supplies.removeAtPosition(position);
            break;

        case 4:
            cout << "Enter supply code to remove: ";
            cin >> code;

            supplies.removeAll(code);
            break;

        case 5:
            cout << "Enter supply code to search: ";
            cin >> code;

            supplies.searchAll(code);
            break;

        case 6:
            supplies.display();
            break;

        case 7:
            supplies.reverseList();
            break;

        case 8:
            supplies.showSizeAndCapacity();
            break;

        case 9:
            supplies.clearList();
            break;

        case 10:
            cout << "Program ended.";
            break;

        default:
            cout << "Invalid choice. Please try again";
        }

    } while (choice != 10);

    return 0;
}