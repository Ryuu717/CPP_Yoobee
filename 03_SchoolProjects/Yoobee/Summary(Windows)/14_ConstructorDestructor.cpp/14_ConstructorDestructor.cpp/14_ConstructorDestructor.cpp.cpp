#include <iostream>
using namespace std;

class Class {
    // private:            
    int value;

public:
    //1. constructor
    // Class(int v = 0){
    //     value = v;
    // }
    Class() {
        value = 0;
    }

    void setValue() {
        cout << "Enter value: ";
        cin >> value;
    }

    void getValue() {
        cout << "Value: " << value << "\n";
    }

    //2. destructor
    ~Class() {
        cout << "object destroyed by destructor\n";
    }
};

int main() {
    Class c;

    // c.setValue();
    // c.getValue();



    return 0;
}