#include <iostream>
#include <vector>
using namespace std;

///////////////////////////////////////////////////////////////////
// Array-3 (vector for Struct)
///////////////////////////////////////////////////////////////////
// struct Struct{
// // public:
//     int value;

// public:
//     Struct(int v = 0){
//         value = v;
//     }
//     void setValue(int value){
//         this->value = value;
//     }
//     int getValue(){
//         return value;
//     }
// };

// int main(){
//     vector <Struct> vectorA;
//     Struct s;

//     char isContinue = 'y';

//     while(isContinue == 'y'){
//         cout << "Enter value: ";
//         cin >> s.value;

//         vectorA.push_back(s);

//         cout << "Continue?(y/n): ";
//         cin >> isContinue;
//     }

//     for (int i = 0; i < vectorA.size(); i++){
//         cout << "Value" << i + 1 << ": " << vectorA[i].getValue() << "\n";
//     }
    
//     return 0;
// }


///////////////////////////////////////////////////////////////////
// Array-3 (vector for Class)
///////////////////////////////////////////////////////////////////
#include <vector>

class Class{
// private:
    int value;

public:
    Class(int v = 0){
        value = v;
    }
    void setValue(int value){
        this->value = value;
    }
    int getValue(){
        return value;
    }
};

int main(){
    vector <Class> vectorA;
    int value;

    char isContinue = 'y';

    while(isContinue == 'y'){
        cout << "Enter value: ";
        cin >> value;

        vectorA.push_back(Class(value1));

        cout << "Continue?(y/n): ";
        cin >> isContinue;
    }

    for (int i = 0; i < vectorA.size(); i++){
        cout << "Value" << i + 1 << ": " << vectorA[i].getValue() << "\n";
    }
    
    return 0;
}