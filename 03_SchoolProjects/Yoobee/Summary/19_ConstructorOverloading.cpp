#include <iostream>
using namespace std;

class Class{
// private:
    int value;

public:
    // Class(){
    //     value = 0;
    // }
    Class(int v = 0){
        value = v;
    }

    Class(Class& c){
        value = c.value;
    }

    void getValue(){
        cout << "Value: " << value << "\n";
    }
};


int main(){
    Class c1(1);
    Class c2(c1);

    c1.getValue();
    c2.getValue();

    return 0;
}