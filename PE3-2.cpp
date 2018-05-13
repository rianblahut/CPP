#include <iostream>
#include <array>
#include <climits>

using namespace std;

int smallestIndex(int a[]);

int main() {
    int a[] = {1, 2, 3, 4, 5};
    cout << smallestIndex(a);
    return 0;
}

int smallestIndex(int a[]) {

    //int smallest = INT_MAX;
    int indexOfSmallest = 0;
    int sizeOfArray = sizeof(a)/sizeof(a[0]);

    for (int i = 1; i < sizeOfArray; i++) {
        if (a[i] < a[indexOfSmallest]) {
            indexOfSmallest = i;
        }
    }
    return indexOfSmallest;

}
