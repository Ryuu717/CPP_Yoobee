#include <iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Ex1) Define list size (based on step1 code)
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Class{
// private:
    int value;

public:
    Class(int v = 0){
        value = v;
    }

    void setValue(){
        cout << "Enter value: ";
        cin >> value;
    }

    void getValue(){
        cout << "Value: " << value << "\n";
    }
};

int main(){
    Class list[3];
    Class c;

    for (int i = 0; i < 3; i++){
        // c.setValue();
        // list[i] = c;
        list[i].setValue();
    }

    for (int i = 0; i < 3; i++){
        list[i].getValue();
    }
    return 0;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Ex2) Define list size (optimized setValue() function)
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// class Class{
// // private:
//     int value;

// public:
//     Class(int v = 0){
//         value = v;
//     }

// //     void setValue(int v){
// //         value = v;
// //     }

//     void setValue(int value){
//         this->value = value;     //if the argument name is the same as the member value name, need to use "this->""
//     }

//     int getValue(){
//         return value;
//     }
// };

// int main(){
//     Class list[3];
//     Class c;

//     int value;

//     for (int i = 0; i < 3; i++){
//         cout << "Enter value" << i + 1 << ": ";
//         cin >> value;

//         // c.setValue(value);
//         // list[i] = c;
//         list[i].setValue(value);
//     }

//     for (int i = 0; i < 3; i++){
//         cout << "Value" << i + 1 << ": " << list[i].getValue() << "\n";
//     }
    

//     return 0;
// }


///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Ex3) Define list size (with Pointer)
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// class Class{
// // private:
//     int value;

// public:
//     Class(int v = 0){
//         value = v;
//     }

//     void setValue(){
//         cout << "Enter value: ";
//         cin >> value;
//     }

//     int getValue(){
//         return value;
//     }
// };

// int main(){
//     Class* list[100];
    
//     int n = 0;
//     char isContinue = 'y';

//     while(isContinue == 'y'){
//         list[n] = new Class();
//         list[n]->setValue();
//         n++;

//         cout << " Do you want to continue?(y / n): "; 
//         cin >> isContinue; 
//     }

//     for (int i = 0; i < 3; i++){
//         cout << "Value" << i + 1 << ": " << list[i]->getValue() << "\n";
//     }

//     return 0;
// }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Ex4) Use vector (Don't define list size)
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// #include <vector>

// class Class{
// public:             //public
//     int value;

// public:
//     Class(int v = 0){
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
//     vector <Class> list;
//     Class c;

//     char isContinue = 'y';
//     int num = 1;

//     while(isContinue == 'y'){
//         cout << "Enter value" << num << ": ";
//         cin >> c.value;         //need to change the parent's access specifier to public

//         list.push_back(c);

//         cout << "Continue?(y/n): ";
//         cin >> isContinue;
//         num++;
//     }

//     for (int i = 0; i < list.size(); i++){
//         cout << "Value" << i + 1 << ": " << list[i].getValue() << "\n";
//     }
    
//     return 0;
// }



///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Ex5) Use vector (keep private member values)
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// #include <vector>

// class Class{
// // private:
//     int value;

// public:
//     Class(int v = 0){
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
//     vector <Class> list;
//     int value;

//     char isContinue = 'y';
//     int num = 1;

//     while(isContinue == 'y'){
//         cout << "Enter value" << num << ": ";
//         cin >> value;

//         list.push_back(Class(value));

//         cout << "Continue?(y/n): ";
//         cin >> isContinue;
//         num++;
//     }

//     for (int i = 0; i < list.size(); i++){
//         cout << "Value" << i + 1 << ": " << list[i].getValue() << "\n";
//     }
    

//     return 0;
// }



///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Ex5) In the case of structure
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// #include <vector>

// struct Struct{
// // public:              //basic access specifier is public
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
//     vector <Struct> list;
//     Struct s;

//     char isContinue = 'y';
//     int num = 1;

//     while(isContinue == 'y'){
//         cout << "Enter value" << num << ": ";
//         cin >> s.value;

//         list.push_back(s);

//         cout << "Continue?(y/n): ";
//         cin >> isContinue;
//         num++;
//     }

//     for (int i = 0; i < list.size(); i++){
//         cout << "Value" << i + 1 << ": " << list[i].getValue() << "\n";
//     }
    
//     return 0;
// }