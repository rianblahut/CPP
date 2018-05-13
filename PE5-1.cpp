#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int main()
{
    char *str;
    int len;
    int i;
    int throwaway;

    str = new char[81];

    cout << "Enter length: ";
    cin >> throwaway;

    cout << endl;
    cout << "Enter a string: ";
    cin.ignore();
    cin.get(str, 80);
    cout << endl;
    cout << "String in upper case letters is:" << endl;

    len = strlen(str);
    for (i = 0; i < len; i++)
        cout << static_cast<char>(toupper(str[i]));
    cout << endl;

    return 0;
}
