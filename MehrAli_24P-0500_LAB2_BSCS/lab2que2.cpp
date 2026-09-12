#include <iostream>
using namespace std;

class PatientList
{
private:
    static const int MAX = 100;

    int patients[MAX];
    int size;

public:

    PatientList()
    {
        size = 0;
    }
    void insertAtEnd(int id)
    {
        if (size == MAX)
        {
            cout << "List is full. Cannot insert patient.\n";
            return;
        }

        patients[size] = id;
        size++;

        cout << "Patient ID inserted successfully.\n";
    }

    void insertAtPosition(int id, int position)
    {
        if (size == MAX)
        {
            cout << "List is full. Cannot insert patient.\n";
            return;
        }

        if (position < 1 || position > size + 1)
        {
            cout << "Invalid position.\n";
            return;
        }

        for (int i = size; i >= position; i--)
        {
            patients[i] = patients[i - 1];
        }

        patients[position - 1] = id;
        size++;

        cout << "Patient ID inserted successfully.\n";
    }
    void deleteAtPosition(int position)
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

        for (int i = position - 1; i < size - 1; i++)
        {
            patients[i] = patients[i + 1];
        }

        size--;

        cout << "Patient deleted successfully.\n";
    }

    void deleteByValue(int id)
    {
        if (size == 0)
        {
            cout << "List is empty. Nothing to delete.\n";
            return;
        }

        int position = -1;

        for (int i = 0; i < size; i++)
        {
            if (patients[i] == id)
            {
                position = i;
                break;
            }
        }

        if (position == -1)
        {
            cout << "Patient ID not found.\n";
            return;
        }

        for (int i = position; i < size - 1; i++)
        {
            patients[i] = patients[i + 1];
        }

        size--;

        cout << "First occurrence of patient ID deleted successfully.\n";
    }

    void search(int id)
    {
        for (int i = 0; i < size; i++)
        {
            if (patients[i] == id)
            {
                cout << "Patient ID found at position "
                     << i + 1 << ".\n";
                return;
            }
        }

        cout << "Patient ID not found.\n";
    }

    void display()
    {
        if (size == 0)
        {
            cout << "List is empty.\n";
            return;
        }

        cout << "Patient IDs: ";

        for (int i = 0; i < size; i++)
        {
            cout << patients[i] << " ";
        }

        cout << endl;
    }

    void displayFirstLast()
    {
        if (size == 0)
        {
            cout << "List is empty.\n";
            return;
        }

        cout << "First Patient ID: " << patients[0] << endl;
        cout << "Last Patient ID: " << patients[size - 1] << endl;
    }

    void showSize()
    {
        cout << "Current number of patients: " << size << endl;
    }
};


int main()
{
    PatientList hospital;

    int choice;
    int id;
    int position;

    do
    {
        cout << "\n========== HOSPITAL APPOINTMENT LIST ==========\n";
        cout << "1. Insert patient ID at end\n";
        cout << "2. Insert patient ID at position\n";
        cout << "3. Delete patient ID by position\n";
        cout << "4. Delete first occurrence of patient ID\n";
        cout << "5. Search for patient ID\n";
        cout << "6. Display all patients\n";
        cout << "7. Display first and last patient\n";
        cout << "8. Display current number of patients\n";
        cout << "9. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter patient ID: ";
            cin >> id;

            hospital.insertAtEnd(id);
            break;

        case 2:
            cout << "Enter patient ID: ";
            cin >> id;

            cout << "Enter position: ";
            cin >> position;

            hospital.insertAtPosition(id, position);
            break;

        case 3:
            cout << "Enter position to delete: ";
            cin >> position;

            hospital.deleteAtPosition(position);
            break;

        case 4:
            cout << "Enter patient ID to delete: ";
            cin >> id;

            hospital.deleteByValue(id);
            break;

        case 5:
            cout << "Enter patient ID to search: ";
            cin >> id;

            hospital.search(id);
            break;

        case 6:
            hospital.display();
            break;

        case 7:
            hospital.displayFirstLast();
            break;

        case 8:
            hospital.showSize();
            break;

        case 9:
            cout << "Program ended.\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 9);

    return 0;
}