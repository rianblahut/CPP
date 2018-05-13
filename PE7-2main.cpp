#include <iostream>
#include <sstream> // for stringstream
#include <algorithm> // for sort
#include "doublyLinkedList.h"

using namespace std;

int main() {

    string rawInput;
    string temp;
    int numList[100];
    int counter = 0;
    int toDelete;
    int toSearch;
    stringstream ss;
    doublyLinkedList<int> daList;

    cout << "Enter numbers for a linked list: ";
    getline(cin, rawInput);
    cout << "Enter number to delete: ";
    cin >> toDelete;
    cout << "Enter number to search for ";
    cin >> toSearch;
    ss << rawInput;

    while(!ss.eof()) {
        ss >> temp;
        int n = stoi(temp);
        if (n == -999) break;
        numList[counter] = n;
        counter++;
    }
    int listToSort[counter];
    for (int i = 0; i < counter; i++) {
        listToSort[i] = numList[i];
    }

    sort(listToSort, listToSort + counter);

    for (int i = 0; i < counter; i++) {
        daList.insert(listToSort[i]);
    }
    cout << "List in ascending order: ";
    daList.print();
    cout << endl;
    cout << "List in descending order: ";
    daList.reversePrint();
    cout << endl;
    bool d = daList.deleteNode(toDelete);
    if (d) {
        cout << "List after deleting " << toDelete << " : ";
        daList.print();
        cout << endl;
    }
    if (daList.search(toSearch)) {
        cout << toSearch << " found in the list.";
    }
    else {
        cout << toSearch << " is not in the list.";
    }

    return 0;
}
