#include <iostream>
#include <vector>
using namespace std;

class Class{
// private: 
    int value;

public:
    // Constructor
    Class(int v = 0){       //Initialize value
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
    ///////////////////////////////////////////////////////////////////
    // Array-1  (int)
    ///////////////////////////////////////////////////////////////////
    // int array[3];
    // int* iPtrArray = &array[0];   //address of first value of array

    // //input
    // for(int i=0; i<3; i++){
    //     cout << "Enter value " << i + 1 << ": ";
    //     cin >> iPtrArray[i];
    // }

    // //output
    // for(int i=0; i<3; i++){
    //     cout << "Value " << i + 1 << ": " << *iPtrArray << "\n";
    //     *iPtrArray++;
    // }


    ///////////////////////////////////////////////////////////////////
    // Array-2  (class)
    ///////////////////////////////////////////////////////////////////
    int n = 0;
    Class* cPtrArray[100];
    char isContinue = 'y';

    while(isContinue == 'y'){
        cPtrArray[n] = new Class();

        cPtrArray[n]->setValue();
        n++;

        cout << "Do you want to continue?(y/n): ";
        cin >> isContinue;
    }

    for(int i = 0; i < n; i++){
        cPtrArray[i]->getValue();
    }

    return 0;
}
