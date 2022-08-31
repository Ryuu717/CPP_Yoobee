// Class member functions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Employee {

    int id;
    string name;
    int age;
    double salary;

public:
    void putData();
    void getData();
};

void Employee::putData() {
    cout << "\nEnter employee ID: ";
    cin >> id;
    cout << "\nEnter employee name: ";
    cin >> name;
    cout << "\nEnter employee age: ";
    cin >> age;
    cout << "\nEnter employee salary: ";
    cin >> salary;
}

void Employee::getData() {
    cout << "\nEmployee ID: " << id;
    cout << "\nEmployee name: " << name;
    cout << "\nEmployee age: " << age;
    cout << "\nEmployee salary: " << salary;
}

int main()
{
    Employee emp;
    emp.putData();
    emp.getData();
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
