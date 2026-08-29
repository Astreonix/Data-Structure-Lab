#include <iostream>
using namespace std;

int main() {
    int rgbVals[] = {80, 80, 80};
    int* ptr = rgbVals;

    for (int i = 0; i < 3; i++) {
        cout << "RGB Value " << i << ": " << *(ptr + i) << endl;
    }

    return 0;
}