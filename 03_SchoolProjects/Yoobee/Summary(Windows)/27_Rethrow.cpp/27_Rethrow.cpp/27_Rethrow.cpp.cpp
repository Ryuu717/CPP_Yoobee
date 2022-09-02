#include <iostream>
using namespace std;


void erroeHander() {
    int a;

    try {
        cout << "Enter a natural numbe(1 - 10): ";
        cin >> a;

        if (a <= 0) throw 1;
        if (a > 10) throw 2;

    }
    catch (...) {
        throw 101;      //rethrow
    }
}


int main() {
    try {
        erroeHander();

    }
    catch (int e) {
        cout << "Error: " << e << "\n";
    }

    return 0;
}