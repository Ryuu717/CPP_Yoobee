#include <iostream>
using namespace std;

struct Struct {
    //public:
    int a;
    float b;
    double c;
    string d;
    char e;
    bool f;

    Struct(int a = 1, float b = 1.1e38, double c = 1.1e308, string d = "string", char e = 'c', bool f = true) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->e = e;
        this->f = f;
    }
    void set(int a, float b, double c, string d, char e, bool f) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->e = e;
        this->f = f;
    }
    void get() {
        cout << "int: \t" << a << "\n";
        cout << "float: \t" << b << "\n";
        cout << "double: " << c << "\n";
        cout << "string: " << d << "\n";
        cout << "char: \t" << e << "\n";
        cout << "bool: \t" << f << "\n";
    }
};


struct Class {
    //private:
    int a;
    float b;
    double c;
    string d;
    char e;
    bool f;

public:
    Class(int a = 1, float b = 1.1e38, double c = 1.1e308, string d = "string", char e = 'c', bool f = true) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->e = e;
        this->f = f;
    }
    void set(int a, float b, double c, string d, char e, bool f) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->e = e;
        this->f = f;
    }
    void get() {
        cout << "int: \t" << a << "\n";
        cout << "float: \t" << b << "\n";
        cout << "double: " << c << "\n";
        cout << "string: " << d << "\n";
        cout << "char: \t" << e << "\n";
        cout << "bool: \t" << f << "\n";
    }
};


int main() {
    ///////////////////////////////////////////////////////////////////
    // Data type-2 (Struct)
    ///////////////////////////////////////////////////////////////////
    Struct s;

    cout << "int: \t" << s.a << "\n";
    cout << "float: \t" << s.b << "\n";
    cout << "double: " << s.c << "\n";
    cout << "string: " << s.d << "\n";
    cout << "char: \t" << s.e << "\n";
    cout << "bool: \t" << s.f << "\n";

    s.set(1, 1.1e38, 1.1e308, "string", 'c', true);
    s.get();


    ///////////////////////////////////////////////////////////////////
    // Data type-3 (Class)
    ///////////////////////////////////////////////////////////////////
    // Class c;

    // // cout << "int: \t" << s.a << "\n";         //can not access to the private members
    // // cout << "float: \t" << s.b << "\n";
    // // cout << "double: " << s.c << "\n";
    // // cout << "string: " << s.d << "\n";
    // // cout << "char: \t" << s.e << "\n";
    // // cout << "bool: \t" << s.f << "\n";

    // c.set(1, 1.1e38, 1.1e308, "string", 'c', true);
    // c.get();

    return 0;
}