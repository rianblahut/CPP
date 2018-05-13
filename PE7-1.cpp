#include <iostream>
#include <string>

using namespace std;

// Insertion Sort
void insertionSort(int list[], int listLength) {

  int firstOutOfOrder, location, temp;

  for (firstOutOfOrder = 1; firstOutOfOrder < listLength; firstOutOfOrder++) {
    if (list[firstOutOfOrder] < list[firstOutOfOrder-1]) {
      temp = list[firstOutOfOrder];
      location = firstOutOfOrder;
      do {
        list[location] = list[location-1];
        location--;
      }
      while (location > 0 && list[location-1] > temp);
      list[location] = temp;
    }
  }
}
// Sequential Search
int sequentialSearch(const int list[], int listLength, int searchItem) {
  int location = 0;
  bool found = false;

  while (location < listLength && !found) {
    if (list[location] == searchItem) found = true;
    else location++;
  }
  if (found) return location;
  else return -1;
}

int main() {

    //string entry; // search number
    int numArray[10];
    int digit; // search term
    unsigned int i; // counter

    cout << "Enter 10 digits, sucka! " << endl;
    for (i = 0; i < 10; i++) {
      cin >> numArray[i];
    }
    cout << "Enter a digit to search: ";
    cin >> digit;

    // sort int array
    insertionSort(numArray, 10);

    // search array
    int result = sequentialSearch(numArray, 10, digit);

    // output
    if (result > -1) cout << digit << " is found at position " << result;
    else cout << digit << " is not in the list";

    return 0;
}
