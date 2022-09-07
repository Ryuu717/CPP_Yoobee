#include <iostream>
using namespace std;

class Class1{
// private:             //Default Access Specifier is private (※ in the case of Struct, the default is public)
    int value1;

public:
    Class1(int v1){
        value1 = v1;
    }

    void getValue1(){
        cout << "Value1: " << value1 << "\n";
    }
};

class Class2{
// private:
    int value2;

public:
    Class2(int v2){
        value2 = v2;
    }
    void getValue2(){
        cout << "Value2: " << value2 << "\n";
    }
};

class Class3 : public Class1, public Class2{        //inherite Class1 and Class2
// private:
    int value3;

public:
    Class3(int v1, int v2, int v3) : Class1(v1), Class2(v2){    //passing arguments
        value3 = v3;
    }

    void getValue3(){
        cout << "Value3: " << value3 << "\n";
    }
};



int main(){
    Class3 c3(1,2,3);

    c3.getValue1();
    c3.getValue2();
    c3.getValue3();

    return 0;
}