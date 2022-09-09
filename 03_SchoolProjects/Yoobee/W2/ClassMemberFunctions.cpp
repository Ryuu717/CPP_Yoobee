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