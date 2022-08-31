#include <iostream>
using namespace std;

class Class{
// private:             //Default Access Specifier is private (※ in the case of Struct, the default is public)
    int value;

public:
    Class(int v = 0){       //Initialize value
        value = v;
    }


    //1. OperatorOverloading (prefix)///////////////////////////////////////////////////////////////////////////
    void operator ++() {
        value = value + 1;
    }

    //2. OperatorOverloading(+)/////////////////////////////////////////////////////////////////////////////////
    Class operator +(Class &obj) {
        Class c;
        c.value = value + obj.value;
        return c; 
    }

    //3. OperatorOverloading(+=)/////////////////////////////////////////////////////////////////////////////////
    Class operator +=(Class &obj) {
        Class c;
        c.value = value + value + obj.value;
        return c; 
    } 

    void getValue(){
        cout << " Value: " << value << "\n";
    }
};


int main(){
    Class c1, c2, c3;

    //1. Call the "void operator ++()" function
    ++c1;
    c1.getValue();

    //2. OperatorOverloading(+)
    c2 = c1 + c1;
    c2.getValue();

    //3. OperatorOverloading(+=)
    c3 = c2 += c1;
    c3.getValue();



    return 0;
}