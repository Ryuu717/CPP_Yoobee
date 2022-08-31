// MultipleThrowCatchException.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// checking x in between (1 to 10 ) or not 

#include <iostream>
using namespace std;

#define error1 "101 : Null value"
#define error2 102

int main(){
    int x;

    try { // outer try - catch
        cout << "Enter x value :";
        cin >> x;

        if (x <= 0){
            throw string(error1);
        }
        else{
          if (x > 10) throw error2;
                cout << "\n x = " << x;
        }

    }catch (string e){
        cout << e;
        cout << " \n Please feed non zero  ...";
    }catch (int i){
        cout << " Error code : " << i << " Out of Range";
    }

    cout << "\n\n\n";
    return 0;
}
