#include <iostream>
using namespace std;

class Class{
public:
    int add(int v1, int v2){
        return v1 + v2;
    }

    double add(double v1, double v2){       //function overloading
        return v1 + v2;
    }

    double add(double v1, double v2, double v3){        //function overloading
        return v1 + v2 + v3;
    }
};


int main(){
    Class c;        //create object

    cout << c.add(1, 1) << "\n";
    cout << c.add(0.1, 0.1) << "\n";
    cout << c.add(0.1, 0.1, 0.1) << "\n";
    cout << c.add(1, 0.1, 0.1) << "\n";

    return 0;
}