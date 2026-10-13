#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Request
{
    int id;
    string studentName;
    string issue;
};

int main()
{
    queue<Request> helpDesk;
    int choice;
    int nextId = 1;

    do
    {
        cout << endl;
        cout << "===== Campus Help Desk =====" << endl;
        cout << "1. Add a request" << endl;
        cout << "2. Serve next request" << endl;
        cout << "3. View next request" << endl;
        cout << "4. Show waiting count" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1)
        {
            Request r;
            r.id = nextId;
            nextId++;
            cout << "Student name: ";
            getline(cin, r.studentName);
            cout << "Issue: ";
            getline(cin, r.issue);
            helpDesk.push(r);
            cout << "Request #" << r.id << " added." << endl;
        }
        else if (choice == 2)
        {
            if (helpDesk.empty())
            {
                cout << "No requests are waiting." << endl;
            }
            else
            {
                Request r = helpDesk.front();
                helpDesk.pop();
                cout << "Serving request #" << r.id << endl;
                cout << "Student: " << r.studentName << endl;
                cout << "Issue: " << r.issue << endl;
            }
        }
        else if (choice == 3)
        {
            if (helpDesk.empty())
            {
                cout << "No requests are waiting." << endl;
            }
            else
            {
                Request r = helpDesk.front();
                cout << "Next request #" << r.id << endl;
                cout << "Student: " << r.studentName << endl;
                cout << "Issue: " << r.issue << endl;
            }
        }
        else if (choice == 4)
        {
            cout << "Requests waiting: " << helpDesk.size() << endl;
        }
        else if (choice == 5)
        {
            cout << "Closing the help desk." << endl;
        }
        else
        {
            cout << "Invalid choice, try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
