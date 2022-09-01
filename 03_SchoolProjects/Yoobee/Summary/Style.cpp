#include <iostream>
#include <vector>
using namespace std;

///////////////////////////////////////////////////////////////////
// 1. With pointer (Array)
///////////////////////////////////////////////////////////////////
class Class{
public:
    int value;

    // constructor
    Class(int v = 0){
        value = v;
    }

    virtual void setValue() = 0;
    virtual void getValue() = 0;
};

class derivedClass : public Class{
public:
    void setValue(){
        cout << "Enter value: ";
        cin >> value;
    }

    void getValue(){
        cout << value << "\n";
    }
};


int main(){
    int n = 0;
    Class* c[100];
    char isContinue = 'y';

    while(isContinue == 'y'){
        c[n] = new derivedClass();

        c[n]->setValue();
        n++;

        cout << "Do you want to continue?(y/n): ";
        cin >> isContinue;
    }

    for(int i = 0; i < n; i++){
        c[i]->getValue();
    }

    return 0;
}

///////////////////////////////////////////////////////////////////
// 2. With pointer (Vector)
///////////////////////////////////////////////////////////////////
// class Class{
// public:
//     int value;

//     // constructor
//     Class(int v = 0){
//         value = v;
//     }

//     virtual void setValue(int v) = 0;
//     virtual void getValue() = 0;
// };

// class derivedClass : public Class{
// public:
//     // derivedClass(int v) : Class(v){};

//     void setValue(int v){
//         value = v;
//     }

//     void getValue(){
//         cout << value << "\n";
//     }
// };

// int main(){
//     vector<Class*> vector;
//     char isContinue = 'y';

//     while(isContinue == 'y'){
//         Class* c = new derivedClass();

//         cout << "Enter value: ";
//         cin >> c->value;            //struct style

//         vector.push_back(c);

//         cout << "Do you want to continue?(y/n): ";
//         cin >> isContinue;
//     }
//     for(int i = 0; i < vector.size(); i++){
//         vector[i]->getValue();
//     }

//     return 0;
// }



///////////////////////////////////////////////////////////////////
// 3. Without pointer
///////////////////////////////////////////////////////////////////
// class Class{
// protected:
//     int value;

// public:
//     // constructor
//     Class(int v = 0){
//         value = v;
//     }

//     virtual void setValue(int v) = 0;
//     virtual void getValue() = 0;
// };

// class derivedClass : public Class{
// public:
//     derivedClass(int v) : Class(v){};       // inherited

//     void setValue(int v){
//         value = v;
//     }

//     void getValue(){
//         cout << value << "\n";
//     }
// };


// int main(){
//     vector<derivedClass> vector;
//     char isContinue = 'y';
//     int value;

//     while(isContinue == 'y'){
//         cout << "Enter value: ";
//         cin >> value;

//         vector.push_back(derivedClass(value));

//         cout << "Do you want to continue?(y/n): ";
//         cin >> isContinue;
//     }
//     for(int i = 0; i < vector.size(); i++){
//         vector[i].getValue();
//     }

//     return 0;
// }