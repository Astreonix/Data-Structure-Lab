#include <iostream>
using namespace std;

class ArrayList
{
private:
    static const int MAX = 100;
    int list[MAX];
    int size;

public:

    ArrayList()
    {
        size = 0;
    }

    void addAtEnd(int id)
    {
        if (size == MAX)
        {
            cout << "List is full. Cannot add student ID.\n";
            return;
        }

        list[size] = id;
        size++;

        cout << "Student ID added successfully.\n";
    }

    void insertAtPosition(int id, int position)
    {
        if (size == MAX)
        {
            cout << "List is full. Cannot insert.\n";
            return;
        }

        if (position < 1 || position > size + 1)
        {
            cout << "Invalid position.\n";
            return;
        }

        for (int i = size; i >= position; i--)
        {
            list[i] = list[i - 1];
        }

        list[position - 1] = id;

        size++;

        cout << "Student ID inserted successfully.\n";
    }

    void removeAtPosition(int position)
    {
        if (size == 0)
        {
            cout << "List is empty. Nothing to delete.\n";
            return;
        }

        if (position < 1 || position > size)
        {
            cout << "Invalid position.\n";
            return;
        }

        cout << "Removed student ID: " << list[position - 1] << endl;

        for (int i = position - 1; i < size - 1; i++)
        {
            list[i] = list[i + 1];
        }

        size--;

        cout << "Student ID removed successfully.\n";
    }

    void search(int id)
    {
        for (int i = 0; i < size; i++)
        {
            if (list[i] == id)
            {
                cout << "Student ID found at position "
                     << i + 1 << ".\n";
                return;
            }
        }

        cout << "Student ID not found.\n";
    }

 
    void display()
    {
        if (size == 0)
        {
            cout << "List is empty.\n";
            return;
        }

        cout << "Currently issued student IDs: ";

        for (int i = 0; i < size; i++)
        {
            cout << list[i] << " ";
        }

        cout << endl;
    }

    void checkStatus()
    {
        if (size == 0)
        {
            cout << "List is EMPTY.\n";
        }
        else if (size == MAX)
        {
            cout << "List is FULL.\n";
        }
        else
        {
            cout << "List is neither empty nor full.\n";
        }
    }
};

int main()
{
    ArrayList students;

    int choice;
    int id;
    int position;

    do
    {
        cout << "\n========== CAMPUS LIBRARY ==========\n";
        cout << "1. Add student ID at end\n";
        cout << "2. Insert student ID at position\n";
        cout << "3. Remove student ID from position\n";
        cout << "4. Search for student ID\n";
        cout << "5. Display all student IDs\n";
        cout << "6. Check whether list is empty or full\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter student ID: ";
            cin >> id;

            students.addAtEnd(id);
            break;

        case 2:
            cout << "Enter student ID: ";
            cin >> id;

            cout << "Enter position: ";
            cin >> position;

            students.insertAtPosition(id, position);
            break;

        case 3:
            cout << "Enter position to remove: ";
            cin >> position;

            students.removeAtPosition(position);
            break;

        case 4:
            cout << "Enter student ID to search: ";
            cin >> id;

            students.search(id);
            break;

        case 5:
            students.display();
            break;

        case 6:
            students.checkStatus();
            break;

        case 7:
            cout << "Program ended.\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 7);

    return 0;
}