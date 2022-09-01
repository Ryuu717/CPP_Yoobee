#include <iostream>
using namespace std;

//funtion prototypes
int a();
float b();
double c();
string d();
char e();
bool f();
void g();


int main(){
    ///////////////////////////////////////////////////////////////////
    // Function-1 (int, float, double, string, char, bool)
    ///////////////////////////////////////////////////////////////////
    cout << "int: \t" << a() << "\n";
    cout << "float: \t" << b() << "\n";
    cout << "double: " << c() << "\n";
    cout << "string: " << d() << "\n";
    cout << "char: \t" << e() << "\n";
    cout << "bool: \t" << f() << "\n";
    g();
    return 0;
}


//funtions
int a(){
    return 1;
}
float b(){
    return 1.1e38;
}
double c(){
    return 1.1e308;
}
string d(){
    return "string";
}
char e(){
    return 'c';
}
bool f(){
    return true;
}
void g(){
    cout << "void: \tvoid\n";
}

