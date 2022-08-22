#include <iostream>
using namespace std;

class Class{
// private: 
    // int value;
    static int value;        // 1.declare static variable ("value" get common(shared))

public:
    Class(int v = 0){
        value = v;
    }

    void setValue(){
        cout << "Enter value: ";
        cin >> value;
    }

    void getValue(){
        cout << "Value: " << value << "\n";
    }
};

// 2.define static variable
int Class::value;

int main(){
    Class c1, c2;

    //set c1
    c1.setValue();
    c1.getValue();

    //set c2
    c2.setValue();
    c2.getValue();

    //show c1 again
    c1.getValue();      // 3.static value is overwritten

    return 0;
}