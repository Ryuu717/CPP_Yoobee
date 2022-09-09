// Nested member function.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Comparing {

    int first, second;

public:
    void input();
    int larger();
    void display();
};

void Comparing::input() {               //Nested Member Function
    cout << "\nEnter first number: ";
    cin >> first;
    cout << "\nEnter second number: ";
    cin >> second;
}

int Comparing::larger() {
    if (first > second) {
        return first;
    }
    else {
        return second;
    }
}

void Comparing::display() {
    cout << "\nThe larger number is: " << larger() << endl;
}

int main()
{
    Comparing comp;
    comp.input();
    comp.display();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
