#include <iostream>
using namespace std;

class Class{
// private:
    int value1;

public:
    Class(int v1 = 0){
        value1 = v1;
    }

    void setValue();
    

    // void getValue();
    friend void getValue(Class c);      //declare friend function (= common function)
};


//nested function
void Class::setValue(){                 //declare the class name with "Class::"         
    cout << "Enter value1: ";
    cin >> value1;
}

// void Class::getValue(){
//     cout << "Value1: " << value1 << "\n";
// }

void getValue(Class c){                  //don't need to declare the class name
    cout << "Value1: " << c.value1 << "\n";
}



int main(){
    Class c;

    c.setValue();      
    getValue(c);

    return 0;
}