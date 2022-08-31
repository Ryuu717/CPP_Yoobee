#include <iostream>
using namespace std;

class A{
    public:
    int num1;
    int num2;

    A(int n1=0, int n2=0){
        n1 = num1;
        n2 = num2;
    }
};

// class B{
//     public:
//     int num1;
//     int num2;

//     B(int n1=0, int n2=0){
//         n1 = num1;
//         n2 = num2;
//     }
// };

// class C{
// }


int main(){
    
    A a(1,1), b(2,2);
    // B b(2,2);


    A c = a + b;
    // cout << c.num1 << endl;

    return 0;
};