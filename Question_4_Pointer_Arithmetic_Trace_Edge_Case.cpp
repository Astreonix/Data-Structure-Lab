#include <iostream>
using namespace std;

int findMax(int* start, int* end) {
    if (start == end) return -1;
    int maxVal = *start;
    int* current = start + 1;

    while (current < end) {
        if (*current > maxVal)
            maxVal = *current;
        current++;
    }
    return maxVal;
}

int main() {
    int data[] = {13, 5, 8, 18};
    int N = 4;

    cout << "Maximum = " << findMax(&data[0], &data[0] + N) << endl;
    return 0;
}