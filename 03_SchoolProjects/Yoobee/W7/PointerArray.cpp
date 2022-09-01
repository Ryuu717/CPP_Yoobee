#include <iostream>
using namespace std;

void calculate(int* ptr, int size){
    int oddCount = 0;
    int evenCount = 0;

    for(int i = 0; i < size; i++){
        if(*ptr%2 == 0){
            oddCount++;
        } else {
            evenCount++;
        }
        *ptr++;
    }
    cout << "Odd counts: " << oddCount << "\n";
    cout << "Even counts: " << evenCount << "\n";
}


int main(){
    int list[5];
    int* ptrArray = &list[0];

    for(int i=0; i<5; i++){
        cout << "Enter value " << i + 1 << ": ";
        cin >> ptrArray[i];
    }

    // for(int i=0; i<5; i++){
    //     cout << "Value " << i + 1 << ": " << *ptrArray << "\n";
    //     *ptrArray++;
    // }


    calculate(ptrArray, 5);
    


    return 0;
}
