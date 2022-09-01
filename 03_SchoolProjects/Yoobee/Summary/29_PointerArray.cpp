#include <iostream>
using namespace std;

int main(){
    ///////////////////////////////////////////////////////////////////
    // Array-1 (without vector)
    ///////////////////////////////////////////////////////////////////
    // int list[3] = {1, 2, 3};
    int list[3];
    int* ptrArray = &list[0];   //address of first value of array

    //input
    for(int i=0; i<3; i++){
        cout << "Enter value " << i + 1 << ": ";
        cin >> ptrArray[i];
    }

    //output
    for(int i=0; i<3; i++){
        cout << "Value " << i + 1 << ": " << *ptrArray << "\n";
        *ptrArray++;
    }

    return 0;
}
