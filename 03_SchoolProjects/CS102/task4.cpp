#include <iostream>
using namespace std;

int main() {
    // 1. Introduction
    cout << "Auckland Power - Customer Bill Generator" << endl << endl;
    cout << "*****************************************" << endl << endl;

    string name;
    int num, units;

    // 2. Get values
    cout << "Enter Customer Name : ";
    cin >> name;
    cout << "Enter Customer Number : ";
    cin >> num;
    cout << "Enter consumed units : ";
    cin >> units;
    cout << endl;

    int amount = (units - 300)*1 + (100*0.8) + (100*0.5)+ 100*0.3;

    // 3. Output
    cout << "Auckland Power - Customer Bill" << endl << endl;
    cout << "*****************************************" << endl << endl;
    cout << "Customer Number : " << num << endl << endl;
    cout << "Customer Name : " << name << endl << endl;
    cout << "Units consumed : " << units << endl << endl;
    cout << "Amount : " << amount << endl << endl;
    cout << "*****************************************" << endl << endl;
    
    return 0;
}