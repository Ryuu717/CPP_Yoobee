#include <iostream>
using namespace std;
#include <vector>

class Class{                        //interface class
protected:
// public:
    int a,b,c;

public:
    void read(){
        cout << "*********************\n";
        cout << "Add\n";
        cout << "*********************\n";
        cout << "Enter the first value: ";
        cin >> a;
        cout << "Enter the second value: ";
        cin >> b;
    }

    void calculate(){
        c = a + b;
    }

    void display(){
        cout << a << " + " << b << " = " << c << "\n\n";
    }
};


int main(){
    vector<Class> v;
    Class c;
    int j = 0;
    char answer = 'y';

    while(answer == 'y') {
        
        c.read();

        v.push_back(c);

        j++;
        cout << "Do you want to continue?(y/n): ";
        cin >> answer;
    }
    
    for(int i = 0; i < size(v); i++){
        v[i].calculate();
        v[i].display();
    }

    return 0;
}