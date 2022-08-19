#include <iostream> 
using namespace std; 

class Base {
    public: 
        // void print() {
        virtual void print() {              //permit overriding
            cout << "Base Function" << endl;
        } 
};

class Derived : public Base { 
    public: 
        void print() { 
            cout << "Derived Function" << endl;
        }
};

int main() { 
    Derived derived1;

    // pointer of Base type & Derived type that points to derivedi 
    Base* b1 = &derived1; 
    Derived* d1 = &derived1;

    // calls member function of Derived class 
    b1->print(); 
    d1->print(); 
    
    return 0; 
}
