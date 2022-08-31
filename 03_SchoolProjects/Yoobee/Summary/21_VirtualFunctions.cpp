#include <iostream>
using namespace std;

class Class{
public:
    // void display(){
    virtual void display(){         //declare virtual function
        cout << "Parent class\n";
    }
};

class DerivedClass : public Class{
public:
    void display(){
        cout << "Derived class\n";
    }
};

int main(){
    // Class* c;
    Class* c = new Class();
    DerivedClass d;
    c = &d;         //able to override only if the function is virtual

    c->display();

    return 0;
}