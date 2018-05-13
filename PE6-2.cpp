#include <iostream>

using namespace std;

int isVowel(char c);
int vowels(string s, int n);

int main() {

    string s;
    int v = 0;

    cout << "Enter string: ";
    getline(cin, s);
    v = vowels(s, s.length());

    cout << v;

    return 0;
}

int isVowel(char c) {
    c = toupper(c);
    if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
        return 1;
    }
    else return 0;
}

int vowels(string s, int n) {

    if (n == 1) return isVowel(s[n-1]);
    return vowels(s, n-1) + isVowel(s[n-1]);

}
