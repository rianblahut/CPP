/* CSCI3731 (C++) Programming Assignment Week 7
April 27, 2018
Rian Blahut

Write a recursive function that returns true if the digits of a positive integer
are in increasing order, otherwise, the function returns false. Also, write a
program to test your function.
*/

#include <iostream>

using namespace std;

// Function Declarations
bool isIncreasing(int n);
  // This function returns true if all digits of the number are increasing
  // It returns false if there are any same or decreasing digits

int main() {

  int n = 12345; // input is hard coded for easy testing
  bool answer = isIncreasing(n); // function call

  // output
  if (answer) cout << "Increasing";
  else cout << "Not Increasing";

  return 0;
}

// Function Definitions

bool isIncreasing(int n) {
  if (n/10 == 0) return true; // only a single digit (at right) (base case)
  if ((n - (n/10)*10) <= (n/10 - (n/100)*10)) return false; // compares right digit with right-1
  return isIncreasing(n/10); // keeps checking with farther left digits
}

/* Assignment Comments
1. This program works, with the exception of having a 0 as the leading digit.
2. The key function checks digits from right to left to determine if they are
increasing. It uses division by 10 or 100, then multiplication by 10 (and
subtraction) to isolate the digits in question, then compares. Any two digits
are the same or decreasing, it returns false. If they are increasing, it calls
the function again to check the next two digits in line.
3. I tested by manually entering various combinations. The boundary case of a
single digit passes. All 10 digits fail as the first is a 0, which C++ treats as
an octal. 123456789 passes though.
4. I learned that any ints that start with 0 are treated as octals (and no
longer like 9's). Other difficulties involved finding out how to separate the
digits using math.
5. I did find an article on geeksforgeeks.org on checking if an array is sorted,
and while not a perfect match it was helpful in organizing my algorithm toward
a single number.
6. None.
*/

/* isIncreasing function with full debug output

bool isIncreasing(int n) {
  cout << "Checking " << n << endl;
  if (n/10 == 0) {
      cout << "Base case: n/10 == 0, where n = " << n << endl;
      return true;
  }
  if ((n - (n/10)*10) <= (n/10 - (n/100)*10)) {
      cout << "(n - (n/10)*10) <= (n/10 - (n/100)*10)" << endl;
      cout << (n - (n/10)*10) << " <= " << (n/10 - (n/100)*10) << endl;
      return false;
  }
  cout << (n - (n/10)*10) << " > " << (n/10 - (n/100)*10) << endl;
  cout << "Recursing!" << endl;
  return isIncreasing(n/10);
}

*/
