#include <iostream>
#include <string>

using namespace std;

class romanType {
    public:
    string userEntry;
    int decimal = 0;
    const int M = 1000;
    const int D = 500;
    const int C = 100;
    const int L = 50;
    const int X = 10;
    const int V = 5;
    const int I = 1;

    void setRoman (string uE) {
        userEntry = uE;
    }
    int getValueOfNum(char c) {
        int a = -1;
        switch (c) {
                case 'M':
                    a = 1000;
                    break;
                case 'D':
                    a = 500;
                    break;
                case 'C':
                    a = 100;
                    break;
                case 'L':
                    a = 50;
                    break;
                case 'X':
                    a = 10;
                    break;
                case 'V':
                    a = 5;
                    break;
                case 'I':
                    a = 1;
                    break;
            }
        return a;
    }
    int convertToDec() {
        for (unsigned int i = 0; i < userEntry.length(); i++) {
            int a = getValueOfNum(userEntry[i]);
            if (i+1 < userEntry.length()) {
                int b = getValueOfNum(userEntry[i+1]);
                if (a >= b) {
                    decimal += a;
                }
                else {
                    decimal += (b - a);
                    i++;
                }
            }
            else {
                decimal += a;
                i++;
            }
        }
        return decimal;
    }
};

class romanType;

int main() {

    cout << "Enter Roman Numeral: ";
    string userEntry;
    cin >> userEntry;

    romanType r;
    r.setRoman(userEntry);
    int d = r.convertToDec();
    cout << "Arabic Numeral: " << d;

    return 0;
}
//CXIIV 115, IIIVX 6, MMXVII 2017
