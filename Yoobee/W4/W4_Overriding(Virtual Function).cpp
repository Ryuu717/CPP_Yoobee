#include <iostream>
using namespace std;

class base{
    public:
        virtual void print (){
            cout<< "print base class" <<endl; 
        }
    
        void show (){
            cout<< "show base class" <<endl;
        }
};

class derived : public base{
    public:
        void print () {
            cout<< "print derived class" << endl; 
        }
    
        void show (){
            cout<< "show derived class" << endl; 
        }
};

//main function
int main() 
{
    base *bptr;     //pointer to base class
    derived d;
    bptr = &d;      //put address of d1 in pointer
    
    //virtual function, binded at runtime (Runtime polymorphism)
    bptr->print(); 

    // Non-virtual function, binded at compile time
    bptr->show(); 
    return 0;
} 
