#include <iostream>
using namespace std;

class Class {
    // private:
public:
    int value;
    string message;

public:
    Class(int v = 0, string m = " ") {
        value = v;
        message = m;
    }
    void function() {

    }
};


int main() {
    int a;

    try {
        cout << "Enter a natural numbe(1 - 10): ";
        cin >> a;

        if (a <= 0) {
            //throw 101;
        }
        else if (a > 10) {
            throw Class(a, "Enter less than 10");
        }

    }
    catch (Class e) {
        cout << "Entered number is " << e.value << "\n";
        cout << e.message << "\n";
    }
}