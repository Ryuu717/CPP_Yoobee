#include <iostream>
using namespace std;

class FLOAT{
// private:             //Default Access Specifier is private (※ in the case of Struct, the default is public)
    float a;
    float a1,a2;

public:
    // Constructor
    // FLOAT(float a1, float a2){ 
    //     this->a1 = a1;
    //     this->a2 = a2;
    // }
    FLOAT(float a1=0, float a2=0){ 
        this->a1 = a1;
        this->a2 = a2;
    }

    void add(float a1=0, float a2=0){
        a = a1 + a2;
    }

    void display(){
        cout << "a1 + a2 = " << a << "\n";
    }
};


int main(){
    FLOAT f;

    f.add(1,1);       
    f.display();

    return 0;
}