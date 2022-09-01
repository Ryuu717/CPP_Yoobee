#include <iostream>
using namespace std;

int main(){
    int x = 1; 
    int y = 2;

    int* ptr1 = &x;
    int* ptr2 = &y;

    cout << "Address: \n";
    cout << " x" << ptr1 << "\n";
    cout << " y" << ptr2 << "\n";

    cout << "Value: \n";
    cout << " x" << *ptr1 << "\n";
    cout << " y" << *ptr2 << "\n";

    return 0;
}
