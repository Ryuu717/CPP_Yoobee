#include <iostream>
using namespace std;
#include <vector>

class Class {                        //interface class
protected:
    int a, b, c;

public:
    virtual void read() = 0;        //pure virtual function
    virtual void calculate() = 0;
    virtual void display() = 0;
};

class Add : public Class {
public:
    void read() {
        cout << "*********************\n";
        cout << "Add\n";
        cout << "*********************\n";
        cout << "Enter the first value: ";
        cin >> a;
        cout << "Enter the second value: ";
        cin >> b;
    }

    void calculate() {
        c = a + b;
    }

    void display() {
        cout << a << " + " << b << " = " << c << "\n\n";
    }
};

class Sub : public Class {
public:
    void read() {
        cout << "*********************\n";
        cout << "Subtract\n";
        cout << "*********************\n";
        cout << "Enter the first value: ";
        cin >> a;
        cout << "Enter the second value: ";
        cin >> b;
    }

    void calculate() {
        c = a - b;
    }

    void display() {
        cout << a << " - " << b << " = " << c << "\n\n";
    }
};

class Multi : public Class {
public:
    void read() {
        cout << "*********************\n";
        cout << "Multiplication\n";
        cout << "*********************\n";
        cout << "Enter the first value: ";
        cin >> a;
        cout << "Enter the second value: ";
        cin >> b;
    }

    void calculate() {
        c = a * b;
    }

    void display() {
        cout << a << " x " << b << " = " << c << "\n\n";
    }
};

int main() {
    Class* add = new Add();
    Class* sub = new Sub();
    Class* multi = new Multi();

    Class* c[] = { add, sub, multi };

    // for(int i = 0; i < 3; i++){
    for (int i = 0; i < sizeof(c) / sizeof(*c); i++) {
        c[i]->read();
        c[i]->calculate();
        c[i]->display();
    }

    return 0;
}