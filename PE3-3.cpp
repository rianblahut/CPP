#include <iostream>

using namespace std;

struct computerType
{
    string manufacturer;
    string modelType;
    string processorType;
    int ram;
    int hardDriveSize;
    int yearBuilt;
    double price;
};

int main() {
    struct computerType myComp;

    //get input
    cout << "Enter manufacturer: ";
    getline(cin, myComp.manufacturer);
    cout << "Enter model: ";
    getline(cin, myComp.modelType);
    cout << "Enter processor: ";
    getline(cin, myComp.processorType);
    cout << "Enter RAM size (in GB): ";
    cin >> myComp.ram;
    cout << "Enter HD size (in GB): ";
    cin >> myComp.hardDriveSize;
    cout << "Enter year built: ";
    cin >> myComp.yearBuilt;
    cout << "Enter price: ";
    cin >> myComp.price;

    //output
    cout << "Manufacturer: " << myComp.manufacturer << endl;
    cout << "Model: " << myComp.modelType << endl;
    cout << "Processor: " << myComp.processorType << endl;
    cout << "RAM: " << myComp.ram << endl;
    cout << "Hard Drive Size: " << myComp.hardDriveSize << endl;
    cout << "Year Built: " << myComp.yearBuilt << endl;
    cout << "Price: " << myComp.price << endl;

    return 0;
}
