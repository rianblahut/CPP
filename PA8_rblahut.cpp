/* CSCI3731 (C++) Programming Assignment Week 8
Cinco de Mayo, 2018
Rian Blahut

Sports Store Inventory Manager Report Program

*/

#include <iostream>
#include <iomanip> //for dollar output formatting
#include <vector>
#include <string>
#include <algorithm> //for sorting

using namespace std;

//This struct holds info on each group of sporting goods
struct item {
  int itemID;
  string itemName;
  int pOrdered;
  int pInStore;
  int pSold;
  double manufPrice;
  double sellingPrice;

  //constructor
  item(int i, string iN, int po, int pi, int ps, double mp, double sp) {
    itemID = i;
    itemName = iN;
    pOrdered = po;
    pInStore = pi;
    pSold = ps;
    manufPrice = mp;
    sellingPrice = sp;
  }
};

// Function Declarations
void importData(vector<item> &storeInv); // Populates all data
bool compareNames(item& x, item& y); // Used by sort to sort items by itemName
void checkInStock(vector<item> &storeInv); // Checks to see if item is in stock.
void buyItem(vector<item> &storeInv); // Customer buys an item (by name and number)
void priceCheck(vector<item> &storeInv); // Checks price of an item
void printInventory(vector<item> &storeInv); // Prints table with status of all inventory items

int main() {

  // Initialize vector, import data, and sort
  vector<item> storeInventory;
  importData(storeInventory);
  sort(storeInventory.begin(), storeInventory.end(), compareNames);

  cout << "Welcome to the Dakine Sport Store!" << endl;

  // Main loop of Program
  while (true) {
    // Present menu
    cout << "Enter one of the following options:" << endl;
    cout << "1. Check if item is in stock" << endl;
    cout << "2. Check an item's price" << endl;
    cout << "3. Buy an item" << endl;
    cout << "4. Print inventory" << endl;
    cout << "9. Exit program" << endl;

    int choice;
    cin >> choice;

    // Call appropriate function
    if (choice == 1) checkInStock(storeInventory);
    else if (choice == 2) priceCheck(storeInventory);
    else if (choice == 3) buyItem(storeInventory);
    else if (choice == 4) printInventory(storeInventory);
    else if (choice == 9) break; //exits while loop, program terminates
    else cout << "Invalid command, try again" << endl;
  }

  return 0;
}

// Function Definitions
void importData(vector<item> &storeInv) {
  storeInv.push_back(item(1111, "basketball", 100, 100, 0, 10.00, 30.00));
  storeInv.push_back(item(2222, "frisbee", 75, 75, 0, 1.00, 15.00));
  storeInv.push_back(item(3333, "baseball", 200, 200, 0, 2.00, 9.00));
  storeInv.push_back(item(4444, "football bat", 30, 30, 0, 7.00, 35.00));
  storeInv.push_back(item(5555, "surfboard", 40, 40, 0, 50.00, 400.00));
  storeInv.push_back(item(6666, "sup", 10, 10, 0, 100.00, 700.00));
  storeInv.push_back(item(7777, "shotgun", 15, 15, 0, 100.00, 300.00));
}

bool compareNames(item& x, item& y) {return x.itemName < y.itemName;}

void checkInStock(vector<item> &storeInv) {
  bool found = false;
  string query;
  cout << "Enter item to check stock status: ";
  cin >> query;

  //loops through vector checking itemName value
  for (unsigned int i = 0; i < storeInv.size(); i++) {
    if (query == storeInv[i].itemName) {
      found = true;
      break;
    }
  }

  if (found) cout << query << " is in stock!" << endl;
  else cout << query << " is not in stock." << endl;
}

void priceCheck(vector<item> &storeInv) {
  bool found = false;
  string query;
  cout << "Enter item to check price: ";
  cin >> query;

  //loops through vector checking itemName value
  for (unsigned int i = 0; i < storeInv.size(); i++) {
    if (query == storeInv[i].itemName) {
      found = true; //it's in the list, shows price
      cout << fixed << showpoint << setprecision(2);
      cout << query << " costs $" << storeInv[i].sellingPrice << endl;
      break;
    }
  }
  if (found == false) cout << query << " is not in stock." << endl;
}

void buyItem(vector<item> &storeInv) {
  bool found = false;
  string query;
  int quantity;
  cout << "Enter item to purchase: ";
  cin >> query;

  //searches vector for item
  for (unsigned int i = 0; i < storeInv.size(); i++) {
    if (query == storeInv[i].itemName) { //item is found
      found = true;
      cout << "Enter quantity: ";
      cin >> quantity;

      //checks if the user wants too many
      while (quantity > storeInv[i].pInStore) {
        cout << "We don't have that many. Please enter a smaller number: ";
        cin >> quantity;
      }
      //output. Charged amount is price * quantity plus Honolulu GET (gotta pay for that rail)
      cout << fixed << showpoint << setprecision(2);
      cout << "Charged: $" << (storeInv[i].sellingPrice * quantity * 1.04712) << endl;
      //inventory updates:
      storeInv[i].pInStore -= quantity;
      storeInv[i].pSold += quantity;
      break;
    }
  }
  if (found == false) cout << query << " is not in stock." << endl;
}

void printInventory(vector<item> &storeInv) {
  int itemCount = 0; //accumulation variables for count and value of inventory
  double invValue = 0.0;

  //header
  cout << "                     Dakine Sports Store Report" << endl; //spaced 21 from left
  cout << setw(6) << "ItemID"
    << setw(14) << "itemName"
    << setw(9) << "pOrdered"
    << setw(9) << "pInstore"
    << setw(6) << "pSold"
    << setw(11) << "manufPrice"
    << setw(13) << "sellingPrice" << endl; //68 wide
  //each line of the report
  for (unsigned int i = 0; i < storeInv.size(); i++) {
    cout << setw(6) << storeInv[i].itemID
    << setw(14) << storeInv[i].itemName
    << setw(9) << storeInv[i].pOrdered
    << setw(9) << storeInv[i].pInStore
    << setw(6) << storeInv[i].pSold
    << setw(11) << storeInv[i].manufPrice
    << setw(13) << storeInv[i].sellingPrice << endl;

    //increments values on this line for totals
    itemCount += storeInv[i].pInStore;
    invValue += (storeInv[i].sellingPrice * storeInv[i].pInStore);
  }

  //output of total values and number of items
  cout << fixed << showpoint << setprecision(2);
  cout << "Total Inventory: $" << invValue << endl;
  cout << "Total number of items in the Store: " << itemCount << endl;

}


/* Assignment Comments
1. This program works, with the exception of a file-based input for store data.
I was unable to get that to work with the online compiler I was using. If I was
able to use a real compiler or IDE I would use a separate file to input. Instead,
I ended up hard coding it.
2. This program first builds a vector to hold the items, then imports the data
into the vector in the form of structs. It then sorts the vector by itemName.
Afterward, it prompts the user using a menu in a while loop, and calls separate
functions for each choice. Most of them involve looping through the vector to
see if the requested item is in stock before doing something with it.
3. I tested each component as I went along, trying values. I incorporated some
input validation in the form of while loops.
4. I definitely learned how the vector works. Prior to this I didn't know
anything about it. I encountered difficulties trying to figure out how to enter
a text file into the online compiler but ended up giving up.
5. I used some of the vector references in the "Other Resources" folder, as well
as cplusplus.com and a healthy dose of Stack Overflow.
6. None.
*/
