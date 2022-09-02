#include <iostream>
using namespace std;

class Class {
    // private:             //Default Access Specifier is private (※ in the case of Struct, the default is public)
    int value;

public:
    // Constructor
    Class(int v = 0) {       //Initialize value
        value = v;
    }

    void setValue() {
        cout << "Enter value: ";
        cin >> value;
    }

    void getValue() {
        cout << "Value: " << value << "\n";
    }
};


int main() {
    Class c;        //create object

    // c.value = 1;   //value is private and inaccessible
    c.setValue();       //value is accessible from public function
    c.getValue();

    return 0;
}