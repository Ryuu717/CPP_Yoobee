#include <iostream>
using namespace std;

class Class{
public:
    virtual void display() = 0;     //pure virtual function (like a blueprint)
    // {
    //     cout << "Parent class\n";
    // }
};

class DerivedClass : public Class{
public:
    void display(){
        cout << "Derived class\n";
    }
};

int main(){
    // Class c;        //can’t make object from abstract class
    Class* c;
    DerivedClass d;
    c = &d;         //able to override only if the function is virtual

    c->display();

    return 0;
}