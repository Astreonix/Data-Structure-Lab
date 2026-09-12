#include <iostream>
using namespace std;

class ProductList
{
private:
    static const int MAX = 100;

    int products[MAX];
    int size;

public:

    ProductList()
    {
        size = 0;
    }

    bool exists(int id)
    {
        for (int i = 0; i < size; i++)
        {
            if (products[i] == id)
            {
                return true;
            }
        }

        return false;
    }

    void addAtEnd(int id)
    {
        if (size == MAX)
        {
            cout << "List is full. Cannot add product.\n";
            return;
        }

        if (exists(id))
        {
            cout << "Duplicate product ID. Product already exists.\n";
            return;
        }

        products[size] = id;
        size++;

        cout << "Product added successfully.\n";
    }

    void insertAtPosition(int id, int position)
    {
        if (size == MAX)
        {
            cout << "List is full. Cannot insert product.\n";
            return;
        }

        if (exists(id))
        {
            cout << "Duplicate product ID. Product already exists.\n";
            return;
        }

        if (position < 1 || position > size + 1)
        {
            cout << "Invalid position.\n";
            return;
        }

        for (int i = size; i >= position; i--)
        {
            products[i] = products[i - 1];
        }

        products[position - 1] = id;
        size++;

        cout << "Product inserted successfully.\n";
    }

    void removeByID(int id)
    {
        if (size == 0)
        {
            cout << "List is empty. Nothing to remove.\n";
            return;
        }

        int position = -1;

        for (int i = 0; i < size; i++)
        {
            if (products[i] == id)
            {
                position = i;
                break;
            }
        }

        if (position == -1)
        {
            cout << "Product ID not found.\n";
            return;
        }

        for (int i = position; i < size - 1; i++)
        {
            products[i] = products[i + 1];
        }

        size--;

        cout << "Product removed successfully.\n";
    }

    void removeByPosition(int position)
    {
        if (size == 0)
        {
            cout << "List is empty. Nothing to remove.\n";
            return;
        }

        if (position < 1 || position > size)
        {
            cout << "Invalid position.\n";
            return;
        }

        // Shift elements to the left
        for (int i = position - 1; i < size - 1; i++)
        {
            products[i] = products[i + 1];
        }

        size--;

        cout << "Product removed successfully.\n";
    }

    void search(int id)
    {
        for (int i = 0; i < size; i++)
        {
            if (products[i] == id)
            {
                cout << "Product ID found at position "
                     << i + 1 << ".\n";
                return;
            }
        }

        cout << "Product ID not found.\n";
    }
    void display()
    {
        if (size == 0)
        {
            cout << "Inventory is empty.\n";
            return;
        }

        cout << "Product IDs: ";

        for (int i = 0; i < size; i++)
        {
            cout << products[i] << " ";
        }

        cout << endl;
    }

    void countProducts()
    {
        cout << "Number of products: " << size << endl;
    }

    void checkProduct(int id)
    {
        if (exists(id))
        {
            cout << "Product exists in the inventory.\n";
        }
        else
        {
            cout << "Product does not exist in the inventory.\n";
        }
    }
};


int main()
{
    ProductList inventory;

    int choice;
    int id;
    int position;

    do
    {
        cout << "\n========== ONLINE STORE INVENTORY ==========\n";
        cout << "1. Add product at end\n";
        cout << "2. Insert product at position\n";
        cout << "3. Remove product by ID\n";
        cout << "4. Remove product by position\n";
        cout << "5. Search product ID\n";
        cout << "6. Display products\n";
        cout << "7. Count products\n";
        cout << "8. Check whether product exists\n";
        cout << "9. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter product ID: ";
            cin >> id;

            inventory.addAtEnd(id);
            break;

        case 2:
            cout << "Enter product ID: ";
            cin >> id;

            cout << "Enter position: ";
            cin >> position;

            inventory.insertAtPosition(id, position);
            break;

        case 3:
            cout << "Enter product ID to remove: ";
            cin >> id;

            inventory.removeByID(id);
            break;

        case 4:
            cout << "Enter position to remove: ";
            cin >> position;

            inventory.removeByPosition(position);
            break;

        case 5:
            cout << "Enter product ID to search: ";
            cin >> id;

            inventory.search(id);
            break;

        case 6:
            inventory.display();
            break;

        case 7:
            inventory.countProducts();
            break;

        case 8:
            cout << "Enter product ID: ";
            cin >> id;

            inventory.checkProduct(id);
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