#include <iostream>
using namespace std;

void checkAtIndex(char* arr, int size, int targetIndex) {
    if (targetIndex < 0 || targetIndex >= size) {
        cout << "Invalid targetIndex." << endl;
        return;
    }

    char* p = arr + targetIndex;
    char ch = *p;

    bool vowel = (ch == 'a' || ch == 'e' || ch == 'i' ||
                  ch == 'o' || ch == 'u' ||
                  ch == 'A' || ch == 'E' || ch == 'I' ||
                  ch == 'O' || ch == 'U');

    cout << "Character: " << ch << endl;
    cout << "Is vowel: " << (vowel ? "Yes" : "No") << endl;
    cout << "Pointer address: " << static_cast<void*>(p) << endl;
}

int main() {
    char arr[] = {'M', 'e', 'h', 'r', 'A', 'l', 'i'};
    int size = 7;
    int targetIndex = 3;

    checkAtIndex(arr, size, targetIndex);

    return 0;
}