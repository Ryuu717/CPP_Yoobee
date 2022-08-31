#include <iostream>
using namespace std;


int main(){
    ///////////////////////////////////////////////////////////////////
    // Data type-1 (int, float, double, string, char, bool)
    ///////////////////////////////////////////////////////////////////
    int a = 1;
    float b = 1.1e38;
    double c = 1.1e308;
    string d = "string";
    char e = 'c';
    bool f = true;

    cout << "int: \t" << a << "\n";
    cout << "float: \t" << b << "\n";
    cout << "double: " << c << "\n";
    cout << "string: " << d << "\n";
    cout << "char: \t" << e << "\n";
    cout << "bool: \t" << f << "\n";

    return 0;
}