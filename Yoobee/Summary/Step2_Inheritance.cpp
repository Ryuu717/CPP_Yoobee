#include <iostream>
using namespace std;

class Class{
// private:
    int value;

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

//derived class
class DerivedClass : public Class{
};



int main(){
    // Class c;
    DerivedClass d;

    d.setValue();       //a derived class can also access the parent values
    d.getValue();

    return 0;
}