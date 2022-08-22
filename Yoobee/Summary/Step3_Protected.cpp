#include <iostream>
using namespace std;

class Class{
// private:
    // int value;
protected:
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
public:
    void getParentValue(){
        cout << "Value: " << value << "\n";       //get parent class's value (it's accessible if the access specifier is protected)
    }
};



int main(){
    // Class c;
    DerivedClass d;

    d.setValue();
    // d.getValue();
    d.getParentValue();     //protected(parent class) ->  success,  private(parent class) ->  error,  

    return 0;
}