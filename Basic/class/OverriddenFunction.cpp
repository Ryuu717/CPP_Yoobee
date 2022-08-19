// AccessToOverriddenFunction.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class BaseClass {
public:
    void disp() {
        cout << "\nFunction of Parent Class";
    }
};

class DerivedClass : public BaseClass {
public:
    void disp() {
        cout << "\nFunction of Child Class";
        BaseClass::disp();  // access to Overridden Function
    }
};
int main() {
    // DerivedClass obj = DerivedClass();
    DerivedClass obj;
    obj.disp();   
    return 0;
}
