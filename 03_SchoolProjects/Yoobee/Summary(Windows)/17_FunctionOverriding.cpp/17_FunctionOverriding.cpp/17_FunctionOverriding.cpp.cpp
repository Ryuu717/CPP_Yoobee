#include <iostream>
using namespace std;

class Class {
public:
    void display() {
        cout << "Parent class\n";
    }
};

class DerivedClass : public Class {
public:
    void display() {
        cout << "Derived class\n";          //Override function
    }
};

int main() {
    Class c;
    DerivedClass d;

    c.display();
    d.display();

    return 0;
}