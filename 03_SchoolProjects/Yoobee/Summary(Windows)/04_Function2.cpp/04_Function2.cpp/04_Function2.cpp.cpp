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
};



struct Struct* setValue(struct Struct* s);
void getValue(struct Struct* s);

// struct Struct setValue(struct Struct s);
// void getValue(struct Struct s);

int main() {
    ///////////////////////////////////////////////////////////////////
    // Function-2 (Struct)
    ///////////////////////////////////////////////////////////////////
    Struct s;
    Struct* ptr = &s;

    setValue(ptr);
    getValue(ptr);

    // setValue(s);
    // getValue(s);



    return 0;
}


struct Struct* setValue(struct Struct* s) {
    cout << "Enter int: ";
    cin >> s->a;
    cout << "Enter float: ";
    cin >> s->b;
    cout << "Enter double: ";
    cin >> s->c;
    cout << "Enter string: ";
    cin >> s->d;
    cout << "Enter char: ";
    cin >> s->e;
    cout << "Enter bool: ";
    cin >> s->f;
    return s;
}

void getValue(struct Struct* s) {
    cout << "int: \t" << s->a << "\n";
    cout << "float: \t" << s->b << "\n";
    cout << "double: " << s->c << "\n";
    cout << "string: " << s->d << "\n";
    cout << "char: \t" << s->e << "\n";
    cout << "bool: \t" << s->f << "\n";
}

// struct Struct setValue(struct Struct s){
//     cout << "Enter int: ";
//     cin >> s.a;
//     cout << "Enter float: ";
//     cin >> s.b;
//     cout << "Enter double: ";
//     cin >> s.c;
//     cout << "Enter string: ";
//     cin >> s.d;
//     cout << "Enter char: ";
//     cin >> s.e;
//     cout << "Enter bool: ";
//     cin >> s.f;
//     return s;
// }

// void getValue(struct Struct s){
//     cout << "int: \t" << s.a << "\n";
//     cout << "float: \t" << s.b << "\n";
//     cout << "double: " << s.c << "\n";
//     cout << "string: " << s.d << "\n";
//     cout << "char: \t" << s.e << "\n";
//     cout << "bool: \t" << s.f << "\n";
// }