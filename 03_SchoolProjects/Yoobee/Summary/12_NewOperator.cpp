#include <iostream>
using namespace std;

class Class{
// private:             
    int value1;

public:
    Class(int v1 = 0){
        value1 = v1;
    }

    void setValue(){
        cout << "Enter value1: ";
        cin >> value1;
    }

    void getValue(){
        cout << "Value1: " << value1 << "\n";
    }
};

int main(){
    // Class c;
    // c.setValue();
    // c.getValue();

    Class* c = new Class();             //new operator
    c->setValue();
    c->getValue();

    return 0;
}