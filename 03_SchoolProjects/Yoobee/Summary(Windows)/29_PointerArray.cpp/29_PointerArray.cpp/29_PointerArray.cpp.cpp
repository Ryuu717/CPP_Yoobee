#include <iostream>
#include <vector>
using namespace std;

int main() {
    ///////////////////////////////////////////////////////////////////
    // Array-1 
    ///////////////////////////////////////////////////////////////////
    // int array[3] = {1, 2, 3};
    int array[3];
    int* ptrArray = &array[0];   //address of first value of array

    //input
    for (int i = 0; i < 3; i++) {
        cout << "Enter value " << i + 1 << ": ";
        cin >> ptrArray[i];
    }

    //output
    for (int i = 0; i < 3; i++) {
        cout << "Value " << i + 1 << ": " << *ptrArray << "\n";
        *ptrArray++;
    }


    return 0;
}