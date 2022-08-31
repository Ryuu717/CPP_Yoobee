#include "iostream"
using namespace std;

namespace namespace1 {
    int age = 10;
}

namespace namespace2 {
    int age = 20;
}

int main(){
    // int age = 10;
    // int age = 20;
    // cout << age << endl;

    cout << namespace1::age << endl;

    return 0;
}