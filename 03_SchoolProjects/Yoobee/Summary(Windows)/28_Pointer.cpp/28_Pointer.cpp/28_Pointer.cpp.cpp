#include <iostream>
using namespace std;

int main() {
    int a = 1;
    int* ptr = &a;

    cout << "Address: \t" << ptr << "\n";
    cout << "Value: \t\t" << *ptr << "\n";

    return 0;
}