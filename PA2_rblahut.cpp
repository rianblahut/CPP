// Programming Assignment Week 2
// CSCI 3731
// Rian Blahut

#include <iostream>
using namespace std;

int main()
{
    //declare variables
    int i; //variable entered by user
    int t = 2; //test divisor

    //user input
    cout << "Enter a positive integer: ";
    cin >> i;

    //This loop checks whether the number is prime
    //The entered number is divided by 2, then 3, etc, up to t = i/2
    while (i % t != 0  && t <= i/2) {
      t++;
    }

    //If a divisor is found, the number is not prime, otherwise, it is
    if (i % t == 0 && i != 2) {
      cout << i << " is not prime.";
    }
    else {
        cout << i << " is prime.";
    }

    return 0;

}
/*
PA2 Notes

1. This program works.
2. My basic approach was incrementally checking divisors, starting with 2. There is a while loop that checks whether the entered number is divisible by the divisor, and if it isn’t, it increments the divisor and tries again. This only goes up to half the entered number as any higher won’t divide anyway.
3. I tested using manual entry, the first several integers, then randomly trying larger numbers.
4. The biggest difficulty I had in this assignment was getting started with an IDE. As a Mac user for some reason the Visual Studio I have installed doesn’t have C++ so I tried the HPU Cloud desktop version. I had checked the first week of class to see if this one had C++ and I forgot to check if it worked, I had major problems with it when I took the C# class. I couldn’t get it to run because I don’t understand Visual Studio. I then tried different versions of Eclipse. The version I have only had Java installed and after attempting to install C++ I ended up having to install a fresh copy with C++ as it’s starting point. This allowed me to at least start a project but it didn’t seem to have anything linked to it (everything from <iostream> to std to cout was “unresolved”). I ended up finding an online compiler. I used http://cpp.sh for this.
5. I consulted an old Java program I had from CSCI 2911 that was similar, and I adjusted the algorithm from that.
6. NA
*/
