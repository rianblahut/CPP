#include <iostream>

using namespace std;

int main() {

    double feet;
    double inches;
    bool success = false;

    while (success == false) {

        try {
            cout << "Enter a length (in feet): ";
            cin >> feet;
            cout << "Enter any inches: ";
            cin >> inches;

            if (feet < 0 || inches < 0 || !cin) {
                throw 0;
            }
            success = true;
            double totalInches = feet * 12;
            totalInches += inches;
            double centimeters = totalInches * 2.54;
            cout << centimeters;
        }
        catch (int x) {
            cout << "A non positive number is entered";
        }
    }

    return 0;
}
