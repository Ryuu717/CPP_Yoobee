// CPP program to illustrate 
// Operator Overloading 

#include<iostream> 
using namespace std; 

class Complex {
    private: 
        string a; 
    
    public: Complex (string a = " ") {
        this->a = a; 
    } 

    Complex operator += (Complex const &obj) {
         Complex res; 
         res.a = a + a + obj.a; 
         return res; 
    }
    
    void print() {
        cout << a << endl; 
    } 
}; 

int main() { 
    Complex c1("a"), c2("b"); 
    Complex c3 = c1 += c2;       // An example call to "operator+" 
    c3.print(); 
};
