#include <iostream>
using namespace std;

int main(){
    int val = 5;  

    for (int i = 1; i <= val; i++){  
        //draw reversed triangle
        for (int j = 1; j <= val-i; j++){  
            cout << " ";
        } 

        for (int k = 1; k <= i; k++){
            cout << "*";
        }

        //draw triangle (from 2 to create vertex)
        for (int l = 2; l <= i; l++){
            cout << "*";
        }
        cout << "\n";
    }  

    return 0;
}