#include <iostream>
using namespace std;

class TwoStacks
{
private:
    int arr[10];

    int top1;
    int top2;

public:
    TwoStacks()
    {
        top1 = -1;
        top2 = 10;
    }

    void push1(int value)
    {
        if (top1 + 1 == top2)
        {
            cout << "Array is full. Stack 1 cannot push." << endl;
        }
        else
        {
            top1++;
            arr[top1] = value;

            cout << value << " pushed into Stack 1." << endl;
        }
    }

    void push2(int value)
    {
        if (top1 + 1 == top2)
        {
            cout << "Array is full. Stack 2 cannot push." << endl;
        }
        else
        {
            top2--;
            arr[top2] = value;

            cout << value << " pushed into Stack 2." << endl;
        }
    }

    void pop1()
    {
        if (top1 == -1)
        {
            cout << "Stack 1 is empty." << endl;
        }
        else
        {
            cout << arr[top1] << " popped from Stack 1." << endl;
            top1--;
        }
    }

    void pop2()
    {
        if (top2 == 10)
        {
            cout << "Stack 2 is empty." << endl;
        }
        else
        {
            cout << arr[top2] << " popped from Stack 2." << endl;
            top2++;
        }
    }

    void display1()
    {
        if (top1 == -1)
        {
            cout << "Stack 1 is empty." << endl;
        }
        else
        {
            cout << "Stack 1: ";

            for (int i = top1; i >= 0; i--)
            {
                cout << arr[i] << " ";
            }

            cout << endl;
        }
    }

    void display2()
    {
        if (top2 == 10)
        {
            cout << "Stack 2 is empty." << endl;
        }
        else
        {
            cout << "Stack 2: ";

            for (int i = top2; i < 10; i++)
            {
                cout << arr[i] << " ";
            }

            cout << endl;
        }
    }
};

int main()
{
    TwoStacks s;

    int choice;
    int value;

    do
    {
        cout << "\n===== TWO STACKS MENU =====" << endl;
        cout << "1. Push Stack 1" << endl;
        cout << "2. Pop Stack 1" << endl;
        cout << "3. Display Stack 1" << endl;
        cout << "4. Push Stack 2" << endl;
        cout << "5. Pop Stack 2" << endl;
        cout << "6. Display Stack 2" << endl;
        cout << "7. Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            s.push1(value);
            break;

        case 2:
            s.pop1();
            break;

        case 3:
            s.display1();
            break;

        case 4:
            cout << "Enter value: ";
            cin >> value;
            s.push2(value);
            break;

        case 5:
            s.pop2();
            break;

        case 6:
            s.display2();
            break;

        case 7:
            cout << "Program ended." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 7);

    return 0;
}