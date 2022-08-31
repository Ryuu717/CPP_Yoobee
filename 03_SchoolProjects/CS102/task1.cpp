#include <iostream>
#include <cmath>    //for sqrt()
using namespace std;

int main() {
    // 1. Get numbers
    int a,b,c;
    cout << "Please enter the number of a: ";
    cin >> a;
    cout << "Please enter the number of b: ";
    cin >> b;
    cout << "Please enter the number of c: ";
    cin >> c;
    cout << endl;

    // 2. Formula
    float x1 = (-b + sqrt(b*b - 4*a*c)) / (2 * a);
    float x2 = (-b - sqrt(b*b - 4*a*c)) / (2 * a);

    // 3. Judge
    if ((b*b - 4*a*c) == 0){
        cout << "Enter a, b, c \t" << a << " " << b <<" " << c <<" " << endl;
        cout << "Roots are real and equal" << endl << endl;
        cout << "x1 = " << x1 << ";" << "\t";
        cout << "x2 = " << x2 << endl;
        cout << "Program ended with exit code: 0" << endl;
    } else if ((b*b - 4*a*c) < 0){
        cout << "Enter a, b, c \t" << a << " " << b <<" " << c <<" " << endl;
        cout << "Roots are imaginary”" << endl << endl;
        cout << "x1 = " << x1 << ";" << "\t";
        cout << "x2 = " << x2 << endl;
        cout << "Program ended with exit code: 0" << endl;
    } else {
        cout << "Enter a, b, c \t" << a << " " << b <<" " << c <<" " << endl;
        cout << "Roots are real and unequal" << endl << endl;
        cout << "x1 = " << x1 << ";" << "\t";
        cout << "x2 = " << x2 << endl;
        cout << "Program ended with exit code: 0" << endl;
    }
    
    return 0;
}