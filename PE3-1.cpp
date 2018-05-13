#include <iostream>
#include <string>

using namespace std;

string removeVowels(string s);
bool isVowel(char a);

int main() {

    string entry;
    string result;

    cout << "Enter a string: ";
    getline(cin, entry);

    result = removeVowels(entry);

    cout << result;

    return 0;
}

bool isVowel(char a) {
    bool isVowel;
    if (a == 'a' || a == 'A' || a == 'e' || a == 'E' || a == 'i' || a == 'I' || a == 'o' || a == 'O' || a == 'u' || a == 'U') {
        isVowel = true;
    }
    else {
        isVowel = false;
    }
    return isVowel;
}

string removeVowels(string s) {
    string r = "";
    for (unsigned int i = 0; i < s.length(); i++) {
        if (!isVowel(s.at(i))) {
            r = r + s.at(i);
        }
    }
    return r;
}
